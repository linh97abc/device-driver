#ifndef __DRIVER_H__
#define __DRIVER_H__

#include "driver_type.h"

namespace driver
{
    class Driver
    {
    private:
        const char *__name;
        Driver *__next;
        Driver_type __type;

    protected:
        Driver(Driver_type dev_type, const char *dev_name);
        virtual void init() = 0;
        ~Driver() = default;

    public:
        static Driver *get_binding(const char *dev_name);
        const char *get_name(void)
        {
            return __name;
        }

        int get_type()
        {
            return __type;
        }
    };

    template <class T>
    class Driver_ref
    {
    private:
        T *inst;

        void validate()
        {
            if (inst && (inst->get_type() != T::type()))
            {
                inst = nullptr;
            }
        }

    public:
        Driver_ref(Driver *dev)
        {
            inst = (T *)dev;
            this->validate();
        }

        Driver_ref(const char *dev_name)
        {
            inst = (T *)Driver::get_binding(dev_name);
            this->validate();
        }

        static void init_all()
        {
            T::init_all();
        }

        T &operator*()
        {
            return *inst;
        }

        T *operator->()
        {
            return inst;
        }
    };

    template <class _If, Driver_type _dev_type>
    class Driver_decl : public Driver, public _If
    {
    protected:
        Driver_decl(const char *dev_name) : driver::Driver(_dev_type, dev_name)
        {
        }

    public:
        static Driver_type type()
        {
            return _dev_type;
        }

        static void init_all()
        {
            static bool did_init = false;

            if (!did_init)
            {
                did_init = true;
                for (int i = 0; i < __num_of_inst; i++)
                {
                    __list_inst[i]->init();
                }
            }
        }

    private:
        static const int __num_of_inst;
        static Driver_decl *const *__list_inst;
    };
}

#define DRIVER_PUBLIC_CONTRUCTOR(dev_impl, dev_type) \
    dev_impl(const char *dev_name) : ::dev_type(dev_name) {}
#endif
