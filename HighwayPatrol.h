#pragma once 

#include "Vehicle.h"

struct Highway;
struct HighwayPatrol : public Vehicle 
{
    HighwayPatrol();

    void scanHighway(Highway* h);
    void pullOver( Vehicle* v, bool willArrest, Highway* h );
    void tryToEvade();
};
