#ifndef __UART_H__
#define __UART_H__

#include "driver.h"

namespace driver
{
    class IUart
    {
    public:
        virtual void send(void) = 0;
    };

    using Uart = Driver_decl<IUart, UART_TYPE>;
    using Uart_ptr = Driver_ref<Uart>;
}

#endif
