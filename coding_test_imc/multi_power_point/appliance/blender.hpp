#ifndef BLENDER_HPP
#define BLENDER_HPP

namespace appliance {

class blender {
  public:
    blender();
    void swizzle();
    void stop();
    bool is_running();
  private:
    bool is_on_;
};

}

#endif
