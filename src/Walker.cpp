#include <chrono>
#include <random>

#include "Walker.h"

using namespace std;

double Walker::randomNormalVariable()
{
    double randomVariable = 0.0;
    return randomVariable;
}

void Walker::Walk()
{
    x += randomNormalVariable();
    y += randomNormalVariable();
    z += randomNormalVariable();
}

Walker::Walker(double initX, double initY, double initZ) :
    x(initX), y(initY), z(initZ) {};

Walker::~Walker(){}
