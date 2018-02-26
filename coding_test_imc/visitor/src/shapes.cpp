#include "shapes.hpp"
#include "visitor.hpp"

using namespace shape_visitor;

circle::circle(const double r)
    : radius_(r)
{}

void circle::accept(visitor& v)
{
    v.visit(this);
}

rectangle::rectangle(const double l, const double w)
    : length_(l), width_(w)
{}

void rectangle::accept(visitor& v)
{
    v.visit(this);
}

triangle::triangle(const double b, const double h)
    : base_(b), height_(h)
{}

void triangle::accept(visitor& v)
{
    v.visit(this);
}
