#ifndef _PLL_H
#define _PLL_H

#include "lm7001.h"

typedef struct {
    lm7001_data_t    lm7001_dev;
}pll_dev_t;

void pll_init(pll_dev_t *device);
void pll_set_freq(pll_dev_t *device, uint32_t frequency);

#endif
