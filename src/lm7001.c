#include <stdio.h>
#include "board.h"
#include "lm7001.h"

void lm7001_init(lm7001_data_t *plldev, uint16_t divider, uint8_t band, uint8_t fref, uint8_t intype)
{
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

    dbg_printf("LM7001 Data: ");
    for(bit = 0; bit < LM7001_PLL_DATA_BITS; bit++)
    {
        if(data & 1)
        {
            LM7001_PLL_DATA_UP();
            dbg_printf("1");
        }
        else
        {
            LM7001_PLL_DATA_DOWN();
            dbg_printf("0");
        }

        delay_us(200);

        LM7001_PLL_CLOCK_UP();

        delay_us(200);

        LM7001_PLL_CLOCK_DOWN();

        data >>= 1;
    }
    dbg_printf("\n");
    LM7001_PLL_ENABLE_DOWN();
    delay_us(200);
}
