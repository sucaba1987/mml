#ifndef OVEN_HPP
#define OVEN_HPP

namespace appliance {

class oven {
  public:
    oven();
    void heatUp();
    void heatOff();
    bool ovenIsOn();
  private:
    bool oven_heating_;
};

}

#endif
