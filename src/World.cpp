#include <iostream>
#include <random>

#include "World.hpp"

int World::computeN()
{
  static std::random_device rd;
  static std::mt19937 e2(rd());
  static std::uniform_real_distribution<> dist(0, 1);
  int sumN=0;
  for (int i = 0; i < nbWalkers; i++)
  {
    B [i] = walkers[i]->W() + dist(e2);
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

double World::NextStep()
{
  walk();
  int newPopSize = computeN();
  nextPopulation(newPopSize);
  return avgB;
}

World::World(int size):
  avgB(-1.0),nbWalkers(size),originalWalkerNb(size)
{
  B = new double [nbWalkers];
  N = new int [nbWalkers];
  walkers = new Walker * [nbWalkers];
  for (int i = 0; i < nbWalkers; i++)
  {
    walkers[i] = new Walker(0.0,0.0,0.0);
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
