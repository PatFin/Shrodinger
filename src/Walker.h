#pragma once

class Walker{
 private :
  double x,y,z;//Coordinates of our walker
  double pX, pY, pZ;//Coordinates of our walker before the last Walk

  double newRadius();
  double oldRadius();
  
 public :
  void Walk();
  double B();
	
  Walker(double initX, double initY, double initZ);
  Walker();
  virtual ~Walker();
};
