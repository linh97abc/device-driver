#include "gpio_1.h"
#include "gpio_2.h"

static Gpio_1 gp1("gpio1/a");
static Gpio_1 gp2("gpio1/b");
static Gpio_1 gp3("gpio1/c");
static Gpio_2 gp4("gpio2/a");
static Gpio_2 gp5("gpio2/b");
static Gpio_2 gp6("gpio2/c");

static Gpio *_gpio[] = {
    &gp1,
    &gp2,
    &gp3,
    &gp4,
    &gp5,
    &gp6,
};

template<>
Gpio *const *Gpio::__list_inst = &_gpio[0];

template<>
const int Gpio::__num_of_inst = sizeof(_gpio) / sizeof(_gpio[0]);