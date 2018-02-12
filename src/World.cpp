#include <iostream>
#include <math.h>
#include <random>

#include "World.hpp"

double World::averageV()
{
  double V;
  for (int i = 0; i < nbWalkers; i++)
  {
    V = walkers[i]->NewV();
  }
  return V/nbWalkers;
}

double World::computeNextPopSize()
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
  double sumN=0.0;

  for (int i = 0; i < nbWalkers; i++)
  {
    N [i] = (B[i]/avgB)*(initNbWalkers/nbWalkers) + dist(e2);
    sumN += N [i];
  }

  return sumN;
}

void World::nextPopulation(double sizeNewPopulation)
{
  // Creating our new population
  Walker ** newWalkers = new Walker * [(int)sizeNewPopulation];
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

  // Preparing for the next step
  nbWalkers = sizeNewPopulation;
  delete [] walkers;
  delete [] B;
  delete [] N;
  walkers = newWalkers;
  B = new double [(int)nbWalkers];
  N = new int [(int)nbWalkers];
}

void World::walk()
{
  for (int i = 0; i < nbWalkers; i++)
  {
    walkers[i]->Walk();
  }
}

int * World::Distribution(int nbPartitions, double maxRadius)
{
  //Init
  int * walkerCount = new int [nbPartitions];
  for (int i = 0; i < nbPartitions; i ++)
  {
    walkerCount[i]=0;
  }
  //Filling the histogram
  for(int i=0; i<nbWalkers; i++)
  {
    int index=0;
    double r = walkers[i]->NewRadius();
    if(r > maxRadius)
    {
      index = nbPartitions-1;
    } else
    {
      index = nbPartitions*(r/maxRadius);
    }
    
    walkerCount[index] ++;
  }

  return walkerCount;
}

double World::NextStep()
{
  extern double tau;
  walk();
  int newPopSize = computeNextPopSize();
  nextPopulation(newPopSize);

  return -log(avgB)/tau;
}

int World::WalkersCount()
{
  return nbWalkers;
}

World::World(double size):
  avgB(-1.0),nbWalkers(size),initNbWalkers(size)
{
  B = new double [(int)nbWalkers];
  N = new int [(int)nbWalkers];
  walkers = new Walker * [(int)nbWalkers];
  for (int i = 0; i < nbWalkers; i++)
  {
    walkers[i] = new Walker();
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
