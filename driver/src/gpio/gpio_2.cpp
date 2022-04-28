#include <gpio.h>
#include <iostream>

class Gpio_2 : public Gpio
{
public:
    Gpio_2(const char *dev_name) : ::Gpio(dev_name) {}

    void write(void)
    {
        std::cout << "Gpio_2" << std::endl;
    }
};

static Gpio_2 b("gpio2/a");
static Gpio_2 a("gpio2/b");
static Gpio_2 c("gpio2/c");
