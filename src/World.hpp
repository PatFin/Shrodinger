#pragma once

#include "Walker.hpp"

class World {

 private:
  double avgB;// Average B of all the walkers. Used in different methods

  Walker ** walkers; //Array of pointers on walkers
  double nbWalkers; //Size of array walkers, number of walkers at any time
  double initNbWalkers; //Initial number of walkers
  double * B;//Array used to store the values of the Walker->B method
  int * N; //Array used to store the number N of the matching index's walker

  //Computes the avg potential of the current walkers
  double averageV();

  //Computes the number of walkers at the next step
  double computeNextPopSize();

  //Computes the walker population size (and arrays B and N) for the next step
  void nextPopulation(double sizeNewPopulation);

  //Makes all the walkers walk once. See Walker::Walk()
  void walk();
 public:
  //Computes an histograms of the number of walkers between radius 0.0 and
  //maxRadius, dividing this domain in nbPartitions partitions. Allocates an
  //array of size nbPartitions whose adress is returned.
  int * Distribution(int nbPartitions, double maxRadius);

  //Returns the current number of walkers alive in the world
  int WalkersCount();

  //Goes one step further in the random walk and returns the new computed value
  //of E
  double NextStep();

  //Constructor specifying the number of initial walkers
  World(double size);

  //Destructor
  virtual ~World();

};
