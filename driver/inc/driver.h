#ifndef __DRIVER_H__
#define __DRIVER_H__

class Driver
{
protected:
    const char *__name;
    Driver *__next;

    Driver(const char *dev_name);
    ~Driver() = default;

public:
    static Driver *get_binding(const char *dev_name);
    const char *get_name(void);
};

#define DRIVER_DECLARE(_driver_type, _interface)          \
    class _driver_type : public Driver, public _interface \
    {                                                     \
    }
#define DRIVER_IMPLEMENT(_driver_type, _interface) class _driver_type : public Driver, public _interface

#endif
