#ifndef TOASTER_HPP
#define TOASTER_HPP

namespace appliance {

class toaster {
  public:
    toaster();
    void startToasting();
    void stopToasting();
    bool onToasting();
  private:
    bool toasting_;
};

}

#endif
