#pragma once

#include "Vehicle.h"

// #include <string>

struct SemiTruck : public Vehicle
{
    SemiTruck(const std::string& n);

    // ~SemiTruck() override { }
    // ~SemiTruck() = default;
    SemiTruck(const SemiTruck&) = default;
    SemiTruck& operator=(const SemiTruck&) = default;

    void honkHorn();
    void pullOver();
    void tryToEvade() override;
};
