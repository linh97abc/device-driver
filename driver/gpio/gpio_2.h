#include <gpio.h>
#include <iostream>

class Gpio_2 : public driver::Gpio
{
public:
    DRIVER_PUBLIC_CONTRUCTOR(Gpio_2, driver::Gpio)

    void write(void)
    {
        std::cout << "Gpio_2" << std::endl;
    }

    void init()
    {
        std::cout << "Gpio_2 init" << std::endl;
    }
};
