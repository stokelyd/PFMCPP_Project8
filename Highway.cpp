#include "Highway.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"

#include <cassert>

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    /*
    depending on the derived type, call the member function that doesn't evade the cops. 
    */
    if( auto* c = dynamic_cast<Car*>(v) )
    {
        c->closeWindows();
    }
    else if( auto* m = dynamic_cast<Motorcycle*>(v) )
    {
        m->lanesplitAndRace();
    }
    else if ( auto* st = dynamic_cast<SemiTruck*>(v) )
    {
        st->honkHorn();
    }
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    /*
    depending on the derived type, call the member function that tries to evade the cops. 

    trucks pull over, but cars and bikes try to evade!!
    */
    if( auto* c = dynamic_cast<Car*>(v) )
    {
        c->tryToEvade();
    }
    else if( auto* m = dynamic_cast<Motorcycle*>(v) )
    {
        v->tryToEvade();
    }
    else if( auto* st = dynamic_cast<SemiTruck*>(v) )
    {
        st->tryToEvade();
    }
}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}
void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}
