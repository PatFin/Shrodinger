#pragma once

#include <iostream>

#include "Walker.hpp"

class World {

 private:
  double avgB;

  Walker ** walkers;
  int nbWalkers;
  int originalWalkerNb;
  double * B;
  int * N;
  
  int computeN();
  void nextPopulation(int sizeNewPopulation);
  void walk();
  
 public:
  double NextStep();

  
  World(int size);
  virtual ~World();

};
