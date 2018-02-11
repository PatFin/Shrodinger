#include "World.hpp"

double tau = 0.01;


const int WALKER_NUMBER = 1000;
const int STEP_NUMBER = 1000;

int main (void)
{
  World world(WALKER_NUMBER);
  for (int i = 0; i < STEP_NUMBER; i++)
  {
    double E = world.NextStep();
    int walkerNb = world.WalkersCount();
    std::cout << i << ";" << walkerNb << ";" << E << ";" << std::endl;
  }
  return 0;
}
