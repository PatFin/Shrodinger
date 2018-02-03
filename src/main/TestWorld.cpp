#include "World.h"

double tau = 0.01;

int main (void)
{
  World world(10);
  world.NextStep(std::cout);
}
