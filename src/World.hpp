#pragma once

#include "Walker.hpp"

class World {

 private:
  double avgB;

  Walker ** walkers;
  int nbWalkers;
  int initNbWalkers;
  double * B;
  int * N;

  int computeNextPopSize();
  void nextPopulation(int sizeNewPopulation);
  void walk();

 public:
  int WalkersCount();
  double NextStep();


  World(int size);
  virtual ~World();

};
