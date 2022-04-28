#include <gpio.h>
#include <iostream>

class Gpio_1 : public Gpio
{
public:
    Gpio_1(const char *dev_name) : ::Gpio(dev_name) {}

    void write(void)
    {
        std::cout << "Gpio_1" << std::endl;
    }
};

static Gpio_1 b("gpio1/a");
static Gpio_1 a("gpio1/b");
static Gpio_1 c("gpio1/c");
