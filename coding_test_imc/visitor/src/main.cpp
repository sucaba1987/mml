#include "shapes.hpp"
#include "visitor.hpp"
#include <iostream>

using namespace std;
using namespace shape_visitor;

int main()
{
    shape* list[3] = {
        new circle(1.0),
        new rectangle(2., 3.),
        new triangle(1., 2.)
    };
    area_visitor m_av;
    for (int i = 0; i < 3; ++i) {
        list[i]->accept(m_av);
        cout << "Shape " << i << " area is " << m_av.area_ << endl;
    }
    for (int i = 0; i < 3; ++i) {
        delete list[i];
        list[i] = nullptr;
    }
    return 0;
}
