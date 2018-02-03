#include <chrono>
#include <random>

#include "NormalVariable.h"

double NormalVariable::nextVal()
{
    return distribution(generator);
}


NormalVariable::NormalVariable (double avg, double stdDev)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator (seed);
    distribution<double> (avg,stdDev);
}

NormalVariable::~NormalVariable () {}
