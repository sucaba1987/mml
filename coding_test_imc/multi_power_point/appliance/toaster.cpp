#include "toaster.hpp"

using namespace appliance;

toaster::toaster()
    : toasting_(false)
{}

void toaster::startToasting()
{
    toasting_ = true;
}

void toaster::stopToasting()
{
    toasting_ = false;
}

bool toaster::onToasting()
{
    return toasting_;
}
