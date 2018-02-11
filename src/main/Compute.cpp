#include "World.hpp"

double tau = 0.01;
double E = 1.0;

const int WALKER_NUMBER = 1000;
const int STEP_NUMBER = 10000;

int main (void)
{
  World world(WALKER_NUMBER);
  for (int i = 0; i < STEP_NUMBER; i++)
  {
    double avgB = world.NextStep();
    std::cout << i << ";" << avgB << ";" << std::endl;
  }
  return 0;
}
