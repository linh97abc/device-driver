#include <uart.h>
#include <iostream>

class Uart_1 : public driver::Uart
{
public:
    DRIVER_PUBLIC_CONTRUCTOR(Uart_1, driver::Uart)

    void send(void)
    {
        std::cout << "Uart_1" << std::endl;
    }

    void init()
    {
        std::cout << "Uart_1 init" << std::endl;
    }
};