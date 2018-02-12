#include "World.hpp"

double tau = 0.01;

const int WALKER_NUMBER = 1000;
const int STEP_NUMBER = 10000;

int main (void)
{
  World world(WALKER_NUMBER);
  for (int i = 0; i < STEP_NUMBER; i++)
  {
    double E = world.NextStep();
    int walkerNb = world.WalkersCount();
    std::cout << i << ";" << walkerNb << ";" << E << ";" << std::endl;

    if ( i % 1000 == 0)
    {
      int partitionNumber = 50;
      double maxRadius = 50.0;
      int * distribution = world.Distribution(partitionNumber, maxRadius);
      for (int i=0; i<partitionNumber;i++)
      {
        std::cerr << distribution[i] << ";" ;
      }
      std::cerr << std::endl;

      delete [] distribution;

    }

  }

  
  return 0;
}
