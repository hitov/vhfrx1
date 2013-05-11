#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lm7001.h"

void lm7001_init(lm7001_data_t *plldev, uint16_t divider, uint8_t band, uint8_t fref, uint8_t intype)
{
    //plldev->data = (0x3FFF & divider) | ((band & 0x0F) << 16) | ((fref & 0x07) << 20) | ((intype & 1) << 23);

    LM7001_PLL_ENABLE_OUTPUT();
    LM7001_PLL_CLOCK_OUTPUT();
    LM7001_PLL_DATA_OUTPUT();
    LM7001_PLL_ENABLE_DOWN();
    LM7001_PLL_CLOCK_DOWN();
    LM7001_PLL_DATA_DOWN();

    plldev->data = LM7001_PLL_DATA_PREPARE(divider, band, fref, intype);
}

void lm7001_prepare_data(lm7001_data_t *plldev, uint16_t divider, uint8_t band, uint8_t fref, uint8_t intype)
{
    plldev->data = LM7001_PLL_DATA_PREPARE(divider, band, fref, intype);
}

void lm7001_wrire(lm7001_data_t *plldev)
{
    uint8_t bit;
    uint32_t data = plldev->data;

    LM7001_PLL_ENABLE_UP();

    //_delay_us(200);

    for(bit = 0; bit < LM7001_PLL_DATA_BITS; bit++)
    {
        if(data & 1)
        {
            LM7001_PLL_DATA_UP();
        }
        else
        {
            LM7001_PLL_DATA_DOWN();
        }

        _delay_us(200);

        LM7001_PLL_CLOCK_UP();

        _delay_us(200);

        LM7001_PLL_CLOCK_DOWN();

        data >>= 1;
    }

    LM7001_PLL_ENABLE_DOWN();
    _delay_us(200);
}
