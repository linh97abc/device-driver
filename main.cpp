#include <iostream>
using namespace std;

#include <gpio.h>
#include <uart.h>

int main()
{
    Gpio::init_all();
    Uart::init_all();

    Gpio_ptr a("gpio1/a");
    Gpio_ptr b("gpio2/b");

    Uart_ptr c("Uart1/a");
    Uart_ptr d("Uart2/a");

    a->write();
    b->write();

    c->send();
    d->send();
    // test
    Gpio::init_all();

    return 0;
}