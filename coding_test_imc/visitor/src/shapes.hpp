#ifndef SHAPES_HPP
#define SHAPES_HPP

namespace shape_visitor {

class visitor;

class shape {
  public:
    virtual void accept(visitor& v) = 0;
    virtual ~shape() {}
};

class circle : public shape {
  public:
    circle(const double r);
    virtual ~circle() {}
    virtual void accept(visitor& v) override;

    double radius_;
};

class rectangle : public shape {
  public:
    rectangle(const double l, const double w);
    virtual ~rectangle() {}
    virtual void accept(visitor& v) override;

    double length_;
    double width_;
};

class triangle : public shape {
  public:
    triangle(const double b, const double h);
    virtual ~triangle() {}
    virtual void accept(visitor& v) override;

    double base_;
    double height_;
};

}

#endif
