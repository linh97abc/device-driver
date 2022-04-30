#include <iostream>
using namespace std;

#include <gpio.h>
#include <uart.h>

int main()
{
    driver::Gpio::init_all();
    driver::Uart::init_all();

    driver::Gpio_ptr a("gpio1/a");
    driver::Gpio_ptr b("gpio2/b");

    driver::Uart_ptr c("Uart1/a");
    driver::Uart_ptr d("Uart2/a");

    a->write();
    b->write();

    c->send();
    d->send();
    // test
    driver::Gpio::init_all();

    return 0;
}