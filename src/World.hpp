#pragma once

#include <iostream>

#include "Walker.hpp"

class World {

 private:
  Walker ** walkers;
  int nbWalkers;
  int originalWalkerNb;
  double * B;
  int * N;
  
  int computeN(std::ostream & out);
  void nextPopulation(int sizeNewPopulation);
  void walk();
  
 public:
  void NextStep(std::ostream & out);

  
  World(int size);
  virtual ~World();

};
