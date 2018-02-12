#pragma once

#include "Walker.hpp"

class World {

 private:
  double avgB;

  Walker ** walkers;
  double nbWalkers;
  double initNbWalkers;
  double * B;
  int * N;

  double averageV();
  int computeNextPopSize();
  void nextPopulation(double sizeNewPopulation);
  void walk();

 public:
  int WalkersCount();
  double NextStep();


  World(double size);
  virtual ~World();

};
