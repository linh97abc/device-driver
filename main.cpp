#include <iostream>
using namespace std;

#include <gpio.h>

class Gpio_1;

int main()
{
    Gpio::init_all();
    Gpio_ptr a("gpio1/a");
    Gpio_ptr b("gpio2/b");

    a->write();
    b->write();

    // test
    Gpio::init_all();

    return 0;
}