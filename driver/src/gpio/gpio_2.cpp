#include <gpio.h>
#include <iostream>

DRIVER_IMPLEMENT(Gpio_2, IGpio)
{
public:
    Gpio_2(const char *dev_name) : ::Driver(dev_name) {}

    void write(void)
    {
        std::cout << "Gpio_2" << std::endl;
    }
};

static Gpio_2 b("gpio2/a");
static Gpio_2 a("gpio2/b");
static Gpio_2 c("gpio2/c");
