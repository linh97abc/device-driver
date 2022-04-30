#include <driver.h>

static int compare_string(const char *s1, const char *s2);

static Driver *__begin = nullptr;

Driver *Driver::get_binding(const char *dev_name)
{
    Driver *iter = __begin;

    while (iter)
    {
        int compare_ret = compare_string(dev_name, iter->__name);

        if (compare_ret == 0)
        {
            return iter;
        }
        else if (compare_ret < 0)
        {
            return nullptr;
        }

        iter = iter->__next;
    }

    return nullptr;
}

static int compare_string(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 < *s2)
        {
            return -1;
        }
        else if (*s1 > *s2)
        {
            return 1;
        }

        s1++;
        s2++;
    }

    if (!*s1 && *s2)
    {
        return -1;
    }
    else if (*s1 && !*s2)
    {
        return 1;
    }

    return 0;
}

Driver::Driver(Driver_type dev_type, const char *dev_name)
{
    this->__name = dev_name;
    this->__type = dev_type;

    if (!__begin)
    {
        __begin = this;
        this->__next = nullptr;
    }
    else
    {
        Driver *i = nullptr;
        Driver *i_next = __begin;

        while (i_next)
        {
            int compare_ret = compare_string(dev_name, i_next->__name);

            if (compare_ret <= 0)
            {
                this->__next = i_next;

                if (i)
                {
                    i->__next = this;
                }
                else
                {
                    __begin = this;
                }

                break;
            }

            i = i_next;
            i_next = i_next->__next;

            if (!i_next)
            {
                i->__next = this;
                this->__next = nullptr;
                break;
            }
        }
    }
}
