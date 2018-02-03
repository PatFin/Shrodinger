#pragma once

#include "Walker.h"

class World {

 private:
  Walker ** walkers;
  int nbWalkers;
  int originalWalkerNb;
  double * B;
  int * N;
  
  int computeN();
  void nextPopulation(int sizeNewPopulation);
  void walk();
  
 public:
  void NextStep();

  
  World(int size);
  virtual ~World();

};
