#ifndef __DRIVER_H__
#define __DRIVER_H__

class Driver
{
protected:
    const char *__name;
    Driver *__next;
    static Driver *__begin;

    Driver(const char *dev_name);
    ~Driver() = default;

public:
    static Driver *get_binding(const char *dev_name);
    const char *get_name(void);
};

#endif
