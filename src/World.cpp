#include <iostream>
#include <math.h>
#include <random>

#include "World.hpp"

int World::computeNextPopSize()
{
  // We first extract all the B's
  avgB = 0.0;
  for (int i = 0; i < nbWalkers; i++)
  {
    double b = walkers[i]->B();
    B [i] = b;
    avgB += b;
  }

  // Preparing some intermediate values for the computation of N
  avgB /= nbWalkers;
  static std::random_device rd;
  static std::mt19937 e2(rd());
  static std::uniform_real_distribution<> dist(0, 1);
  int sumN=0;

  for (int i = 0; i < nbWalkers; i++)
  {
    N [i] = (B[i]/avgB) + dist(e2); //Cast in integer TODO add the population compensation coef
    sumN += N [i];
  }

  return sumN;
}

void World::nextPopulation(int sizeNewPopulation)
{
  // Creating our new population
  Walker ** newWalkers = new Walker * [sizeNewPopulation];
  int j=0; //Index of the next new walker in the new population
  for(int i=0; i < nbWalkers; i++)
  {
    if (N[i] == 0)
    {
      delete walkers[i];
    } else {
      while (N [i] > 1)
      {
        // Copy constructor when needed to multiply the instances
        newWalkers[j] = new Walker(* walkers[i]);
        j++;
        N[i]--;
      }
      newWalkers[j] = walkers[i]; //No copy for the last walker
      j++;
    }
  }

  //Safety Check
  if (j != sizeNewPopulation)
  {
    std::cerr << "--Warning new pop size is " << sizeNewPopulation
	      << " but was filled until " << j << std::endl;
  }

  // Preparing for the next step
  nbWalkers = sizeNewPopulation;
  delete [] walkers;
  delete [] B;
  delete [] N;
  walkers = newWalkers;
  B = new double [nbWalkers];
  N = new int [nbWalkers];
}

void World::walk()
{
  for (int i = 0; i < nbWalkers; i++)
  {
    walkers[i]->Walk();
  }
}

int World::WalkersCount()
{
  return nbWalkers;
}

double World::NextStep()
{
  extern double tau;
  walk();
  int newPopSize = computeNextPopSize();
  nextPopulation(newPopSize);

  return -log(avgB)/tau;
}

World::World(int size):
  avgB(-1.0),nbWalkers(size),initNbWalkers(size)
{
  B = new double [nbWalkers];
  N = new int [nbWalkers];
  walkers = new Walker * [nbWalkers];
  for (int i = 0; i < nbWalkers; i++)
  {
    walkers[i] = new Walker(); //TODO setup factory design
  }
}

World::~World()
{
  for (int i = 0; i < nbWalkers; i++)
  {
    delete walkers[i];
  }
  delete [] walkers;
  delete [] B;
  delete [] N;
}
