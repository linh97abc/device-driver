#ifndef __DRIVER_H__
#define __DRIVER_H__
class Driver
{
private:
    const char *__name;
    Driver *__next;
    int __type;

protected:
    Driver(int dev_type, const char *dev_name);
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

template <class _If, int _dev_type>
class Driver_decl : public Driver, public _If
{
protected:
    Driver_decl(const char *dev_name) : ::Driver(_dev_type, dev_name)
    {
    }

public:
    static int type()
    {
        return _dev_type;
    }

    static void init_all()
    {
        static bool did_init = false;

        if (!did_init)
        {
            did_init = true;
            int num;
            Driver_decl **list = get_list_init(num);
            for (int i = 0; i < num; i++)
            {
                list[i]->init();
            }
        }
    }

private:
    static Driver_decl **get_list_init(int &num);
};

#define DRIVER_PUBLIC_CONTRUCTOR(dev_impl, dev_type) \
    dev_impl(const char *dev_name) : ::dev_type(dev_name) {}
#endif
