#include <chrono>
#include <random>

#include "Walker.h"

using namespace std;


void Walker::Walk()
{
  //TODO
}

double Walker::B()
{
  return 0.0;
}

Walker::Walker(double initX, double initY, double initZ) :
    x(initX), y(initY), z(initZ) {};

Walker::~Walker(){}
