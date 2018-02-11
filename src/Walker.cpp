#include <chrono>
#include <math.h>
#include <random>

#include "Walker.hpp"

using namespace std;

double Walker::newV()
{
  //TODO refactor
  double radius =  sqrt(x*x + y*y + z*z);
  return -1/radius;
}

double Walker::oldV()
{
  //TODO refactor
  double radius = sqrt(pX*pX + pY*pY + pZ*pZ);
  return -1/radius;
}

void Walker::Print(std::ostream & out)
{
  out << x << " " << y << " " << z << std::endl;
}

void Walker::Walk()
{
  extern double tau;
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);
  std::normal_distribution<double> distribution (0.0,1.0);  //TODO to check if this is the correct distribution
  pX = x;
  pY = y;
  pZ = z;

  x += sqrt(tau)*distribution(generator);
  y += sqrt(tau)*distribution(generator);
  z += sqrt(tau)*distribution(generator);

}

double Walker::B()
{
  extern double tau;

  return exp(- tau*(newV() - oldV())/2);
}

Walker::Walker()
{
  std::random_device rd;
  std::mt19937 e2(rd());
  std::uniform_real_distribution<> dist(0, 1);

  x = 0.5 - dist(e2);
  y = 0.5 - dist(e2);
  z = 0.5 - dist(e2);
}

Walker::Walker(double initX, double initY, double initZ) :
  x(initX), y(initY), z(initZ) {}

Walker::~Walker(){}
