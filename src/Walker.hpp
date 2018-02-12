#pragma once

#include <iostream>


class Walker{
 private :
  double x,y,z;//Coordinates of the walker
  double pX, pY, pZ;//Coordinates of our walker before the last Walk

 public :
  //Computes the B of the walker
  double B();

  //Computes the radius of the walker (euclidean distance)
  double NewRadius();
  
  //Computes the radius of the walker before the last "Walk"
  double OldRadius();

  //Computes the current potential of the walker
  double NewV();

  //Computes the potential of the walker before the last "Walk"
  double OldV();

  //Prints the walkers current coordinates
  void Print(std::ostream & out);

  //Makes the walker randomly walk following a normal law centered at 0 and of
  //variance 1. The coordinates are updated.
  void Walk();


  //Constructor defining the original coordinates of the walker
  Walker(double initX, double initY, double initZ);

  //Constructor randomly setting the initial coordinates uniformly in the range
  //[-0.5,0.5].
  Walker();

  //Destructor
  virtual ~Walker();
};
