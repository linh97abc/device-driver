#include <uart.h>
#include <iostream>

class Uart_2 : public driver::Uart
{
public:
    DRIVER_PUBLIC_CONTRUCTOR(Uart_2, driver::Uart)

    void send(void)
    {
        std::cout << "Uart_2" << std::endl;
    }

    void init()
    {
        std::cout << "Uart_2 init" << std::endl;
    }
};