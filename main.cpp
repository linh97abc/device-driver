#include <iostream>
using namespace std;

#include <gpio.h>

class Gpio_1;

int main()
{
    Gpio *a = (Gpio *)Driver::get_binding("gpio1/a");
    Gpio *b = (Gpio *)Driver::get_binding("gpio2/b");

    a->write();
    b->write();

    return 0;
}