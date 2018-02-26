#include "oven.hpp"

using namespace appliance;

oven::oven()
    : oven_heating_(false)
{}

void oven::heatUp()
{
    oven_heating_ = true;
}

void oven::heatOff()
{
    oven_heating_ = false;
}

bool oven::ovenIsOn()
{
    return oven_heating_;
}
