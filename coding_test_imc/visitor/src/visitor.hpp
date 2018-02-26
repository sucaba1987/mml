#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "shapes.hpp"

namespace shape_visitor {

class visitor {
  public:
    virtual void visit(circle* s) = 0;
    virtual void visit(rectangle* s) = 0;
    virtual void visit(triangle* s) = 0;
    virtual ~visitor() {}
};

class area_visitor : public visitor {
  public:
    area_visitor();
    virtual ~area_visitor() {}
    virtual void visit(circle* s) override;
    virtual void visit(rectangle* s) override;
    virtual void visit(triangle* s) override;

    double area_;
};

}

#endif
