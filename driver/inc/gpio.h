#ifndef __GPIO_H__
#define __GPIO_H__

#include "driver.h"

class IGpio
{
public:
    virtual void write(void) = 0;
};

using Gpio = Driver_decl<IGpio, GPIO_TYPE>;
using Gpio_ptr = Driver_ref<Gpio>;

#endif
