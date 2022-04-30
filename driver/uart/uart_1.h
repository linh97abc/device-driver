#include <uart.h>
#include <iostream>

class Uart_1 : public Uart
{
public:
    DRIVER_PUBLIC_CONTRUCTOR(Uart_1, Uart)

    void send(void)
    {
        std::cout << "Uart_1" << std::endl;
    }

    void init()
    {
        std::cout << "Uart_1 init" << std::endl;
    }
};