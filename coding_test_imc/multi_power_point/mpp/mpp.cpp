#include "mpp.hpp"

using namespace std;
using namespace mpp;

void multi_power_point::register_on_callback(Callback cb)
{
    on_func_.emplace_back(cb);
}

void multi_power_point::register_off_callback(Callback cb)
{
    off_func_.emplace_back(cb);
}

void multi_power_point::on()
{
    for(auto& f : on_func_)
        f();
}

void multi_power_point::off()
{
    for(auto& f : off_func_)
        f();
}
