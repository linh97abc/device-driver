#ifndef __GPIO_H__
#define __GPIO_H__

#include "driver.h"

class Gpio : public Driver
{
protected:
    Gpio(const char *dev_name) : ::Driver(dev_name)
    {
    }

public:
    virtual void write(void) = 0;
};

#endif
