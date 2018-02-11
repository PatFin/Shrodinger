#pragma once

#include <iostream>


class Walker{
 private :
  double x,y,z;//Coordinates of our walker
  double pX, pY, pZ;//Coordinates of our walker before the last Walk

  double oldRadius();

 public :
  double newV();
  double oldV();
  void Print(std::ostream & out);
  void Walk();
  double B();

  Walker(double initX, double initY, double initZ);
  Walker();
  virtual ~Walker();
};
