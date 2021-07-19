#include "SemiTruck.h"

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n) { }

void SemiTruck::honkHorn()
{
    setSpeed(65);
    std::cout << name << ": honking the horn." << std::endl;
}

void SemiTruck::pullOver()
{
    setSpeed(0);
    std::cout << name << ": hello officer, what seems to be the problem?" << std::endl;
}

void SemiTruck::tryToEvade() { }
