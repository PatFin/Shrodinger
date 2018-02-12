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
  double computeNextPopSize();
  void nextPopulation(double sizeNewPopulation);
  void walk();
 public:
  int * Distribution(int nbPartitions, double maxRadius);
  int WalkersCount();
  double NextStep();


  World(double size);
  virtual ~World();

};
