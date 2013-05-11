#include "lm7001.h"
#include "pll.h"

void pll_init(pll_dev_t *device)
{
    lm7001_init(&device->lm7001_dev, 1, LM7001_PLL_BAND_B0, LM7001_PLL_FREF_5KHZ, LM7001_PLL_INTYPE_FMIN);
}

void pll_set_freq(pll_dev_t *device, uint32_t frequency)
{
    uint32_t divider;

    divider = frequency / 5000;

    lm7001_prepare_data(&device->lm7001_dev, divider, LM7001_PLL_BAND_B0, LM7001_PLL_FREF_5KHZ, LM7001_PLL_INTYPE_FMIN);
    lm7001_wrire(&device->lm7001_dev);
}
