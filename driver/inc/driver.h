#ifndef __DRIVER_H__
#define __DRIVER_H__

#include "driver_type.h"

#define CONFIG_HAS_LIST_DRIVER false

namespace driver
{
    int compare_string(const char *s1, const char *s2);
    class Driver
    {
    private:
        const char *__name;
        Driver_type __type;
#if CONFIG_HAS_LIST_DRIVER
        Driver *__next;
#endif

    protected:
        Driver(Driver_type dev_type, const char *dev_name);
        virtual void init() = 0;
        ~Driver() = default;

    public:
#if CONFIG_HAS_LIST_DRIVER
        static Driver *get_binding(const char *dev_name);
#endif
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

    public:
        Driver_ref(Driver *dev)
        {
            inst = (T *)dev;
            if (inst && (inst->get_type() != T::type()))
            {
                inst = nullptr;
            }
        }

        Driver_ref(const char *dev_name)
        {
            inst = T::get_dev_by_name(dev_name);
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

        static Driver_decl *get_dev_by_name(const char *name)
        {
            for (int i = 0; i < __num_of_inst; i++)
            {
                int val = compare_string(name, __list_inst[i]->get_name());
                if (val == 0)
                {
                    return __list_inst[i];
                }
            }

            return nullptr;
        }

        template <class T>
        friend class Driver_ref;
    };
}

#define DRIVER_PUBLIC_CONTRUCTOR(dev_impl, dev_type) \
    dev_impl(const char *dev_name) : ::dev_type(dev_name) {}
#endif
