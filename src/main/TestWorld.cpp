#include "World.hpp"

double tau = 0.01;
double E = 1.0;
int main (void)
{
  World world(10);
  world.NextStep();
}
