#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "pll.h"

pll_dev_t pll;

int main(void)
{
#ifdef __AVR__
    DDRC = 0x06;
    PORTC = 1<<1;
#endif

    dbg_printf("Radio startup\n");

    pll_init(&pll);

    delay_ms(100);
    delay_ms(100);
    delay_ms(100);
    delay_ms(100);
    delay_ms(100);
    delay_ms(100);
    delay_ms(100);
    delay_ms(100);
    delay_ms(100);
    delay_ms(100);

    pll_set_freq(&pll, 144800000); //Set frequency in kHz

    for(;;)
    {
#ifdef __AVR__
        PORTC = 1<<1;
        delay_ms(100);
        PORTC = 2<<1;
        delay_ms(100);
#endif
    }
    return 0;
}
