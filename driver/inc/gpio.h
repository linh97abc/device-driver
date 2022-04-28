#ifndef __GPIO_H__
#define __GPIO_H__

#include "driver.h"

class IGpio
{
public:
    virtual void write(void) = 0;
};

DRIVER_DECLARE(Gpio, IGpio);

#endif
