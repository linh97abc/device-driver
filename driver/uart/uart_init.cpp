#include "uart_1.h"
#include "uart_2.h"

static Uart_1 gp1("Uart1/a");
static Uart_1 gp2("Uart1/b");
static Uart_1 gp3("Uart1/c");
static Uart_2 gp4("Uart2/a");
static Uart_2 gp5("Uart2/b");
static Uart_2 gp6("Uart2/c");

static driver::Uart *_Uart[] = {
    &gp1,
    &gp2,
    &gp3,
    &gp4,
    &gp5,
    &gp6,
};

template<>
driver::Uart *const *driver::Uart::__list_inst = &_Uart[0];

template<>
const int driver::Uart::__num_of_inst = sizeof(_Uart) / sizeof(_Uart[0]);