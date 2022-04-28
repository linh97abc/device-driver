#include <gpio.h>
#include <iostream>

DRIVER_IMPLEMENT(Gpio_1, IGpio)
{
public:
    Gpio_1(const char *dev_name) : ::Driver(dev_name) {}

    void write(void)
    {
        std::cout << "Gpio_1" << std::endl;
    }
};

static Gpio_1 b("gpio1/a");
static Gpio_1 a("gpio1/b");
static Gpio_1 c("gpio1/c");
