#include <iostream>

#include "World.hpp"

int World::computeN(std::ostream & out)
{
  int sumN=0;
  double sumB = 0.0;
  for (int i = 0; i < nbWalkers; i++)
  {
    double b = walkers[i]->B();
    std::cerr << "b : " << b << std::endl;

    B [i] = b;
    sumB += b;
  }
  double nb = nbWalkers;
  double originalNb = originalWalkerNb;

  for (int i = 0; i < nbWalkers; i++)
  {
    double n = (B[i]*nbWalkers*nbWalkers)/(sumB*originalNb); //TODO + noise dzeta
    N[i]=n;
    sumN += n;
  }
  out << sumB/nb << ";" << std::endl;
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

void World::NextStep(std::ostream & out)
{
  walk();
  int newPopSize = computeN(out);
  std::cerr << "Population size : " << newPopSize << std::endl;
  //nextPopulation(newPopSize);
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
  delete [] walkers;
  delete [] B;
  delete [] N;
}
