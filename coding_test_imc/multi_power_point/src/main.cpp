#include <vector>
#include <iostream>
#include <functional>
#include "blender.hpp"
#include "oven.hpp"
#include "toaster.hpp"
#include "mpp.hpp"

using namespace std;
using namespace mpp;
using namespace appliance;

void display_status(vector<blender>& my_blenders,
                    vector<oven>& my_ovens,
                    vector<toaster>& my_toasters)
{
    for (size_t i = 0; i < my_blenders.size(); ++i) {
        cout << "Blender " << i << " is "
             << (my_blenders[i].is_running() ? "on" : "off")
             << endl;
    }
    for (size_t i = 0; i < my_ovens.size(); ++i) {
        cout << "Oven    " << i << " is "
             << (my_ovens[i].ovenIsOn() ? "on" : "off")
             << endl;
    }
    for (size_t i = 0; i < my_toasters.size(); ++i) {
        cout << "Toaster " << i << " is "
             << (my_toasters[i].onToasting() ? "on" : "off")
             << endl;
    }
}

int main()
{
    multi_power_point my_switch;
    vector<blender> my_blenders(2);
    vector<oven> my_ovens(3);
    vector<toaster> my_toasters(4);

    for (auto& b: my_blenders) {
        my_switch.register_on_callback(std::bind(&blender::swizzle, &b));
        my_switch.register_off_callback(std::bind(&blender::stop, &b));
    }
    for (auto& b: my_ovens) {
        my_switch.register_on_callback(std::bind(&oven::heatUp, &b));
        my_switch.register_off_callback(std::bind(&oven::heatOff, &b));
    }
    for (auto& b: my_toasters) {
        my_switch.register_on_callback(std::bind(&toaster::startToasting, &b));
        my_switch.register_off_callback(std::bind(&toaster::stopToasting, &b));
    }

    cout << "Before turn on multi_power_point:" << endl;
    display_status(my_blenders, my_ovens, my_toasters);
    my_switch.on();
    cout << "After turn on multi_power_point:" << endl;
    display_status(my_blenders, my_ovens, my_toasters);
    my_switch.off();
    cout << "After turn off multi_power_point:" << endl;
    display_status(my_blenders, my_ovens, my_toasters);

    return 0;
}
