#include <gpio.h>
#include <iostream>

class Gpio_1 : public driver::Gpio
{
public:
    DRIVER_PUBLIC_CONTRUCTOR(Gpio_1, driver::Gpio)

    void write(void)
    {
        std::cout << "Gpio_1" << std::endl;
    }

    void init()
    {
        std::cout << "Gpio_1 init" << std::endl;
    }
};