#pragma once

#include "Vehicle.h"

#include <string>

struct Car : public Vehicle
{
    Car(const std::string& s);
    void closeWindows();

    void tryToEvade();
};
