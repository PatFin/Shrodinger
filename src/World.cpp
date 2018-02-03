#include <iostream>

#include "World.h"

int World::computeN()
{
  int sumN=0;
  double sumB = 0.0;
  for (int i = 0; i < nbWalkers; i++)
  {
    double b = walkers[i]->B();
    B [i] = b;
    sumB += b;
  }
  double nb = nbWalkers;
  double originalNb = originalWalkerNb;

  for (int i = 0; i < nbWalkers; i++)
  {
    int n = (B[i]*nbWalkers)/(sumB*originalNb); //TODO + noise dzeta
    N [i]=n;
    sumN += n;
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
  delete B;
  delete N;
  B = new double [nbWalkers];
  N = new int [nbWalkers];
}

void World::NextStep()
{
  int newPopSize = computeN();
  nextPopulation(newPopSize);
}

void World::walk()
{
  for (int i = 0; i < nbWalkers; i++)
  {
    walkers[i]->Walk();
  }
}

World::World(int size):
  nbWalkers(size),originalWalkerNb(size)
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
  delete walkers;
  delete B;
  delete N;
}
