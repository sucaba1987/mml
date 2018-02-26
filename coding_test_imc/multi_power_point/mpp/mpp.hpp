#ifndef MPP_HPP
#define MPP_HPP

#include <vector>
#include <functional>

namespace mpp {

class multi_power_point {
  public:
    using Callback = std::function<void ()>;

    void register_on_callback(Callback cb);
    void register_off_callback(Callback cb);

    void on();
    void off();

  private:
    std::vector<Callback> on_func_;
    std::vector<Callback> off_func_;
};

}

#endif
