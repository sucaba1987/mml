#include "blender.hpp"

using namespace appliance;

blender::blender()
    : is_on_(false)
{}

void blender::swizzle()
{
    is_on_ = true;
}

void blender::stop()
{
    is_on_ = false;
}

bool blender::is_running()
{
    return is_on_;
}
