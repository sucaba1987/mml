#include "visitor.hpp"

using namespace shape_visitor;

constexpr double PI = 3.141592653589793;

area_visitor::area_visitor()
    : area_(0.)
{}

void area_visitor::visit(circle* s)
{
    area_ = PI * s->radius_ * s->radius_;
}

void area_visitor::visit(rectangle* s)
{
    area_ = s->length_ * s->width_;
}

void area_visitor::visit(triangle* s)
{
    area_ = 0.5 * s->base_ * s->height_;
}
