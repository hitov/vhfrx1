#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "pll.h"

pll_dev_t pll;

int main(void)
{
    DDRC = 0x06;
    PORTC = 1<<1;
    pll_init(&pll);

    _delay_ms(100);
    _delay_ms(100);
    _delay_ms(100);
    _delay_ms(100);
    _delay_ms(100);
    _delay_ms(100);
    _delay_ms(100);
    _delay_ms(100);
    _delay_ms(100);
    _delay_ms(100);
    pll_set_freq(&pll, 100800000); //Set frequency in kHz
    for(;;)
    {
        PORTC = 1<<1;
        _delay_ms(100);
        PORTC = 2<<1;
        _delay_ms(100);
        //pll_set_freq(&pll, 144800000); //Set frequency in kHz
    }
    return 0;
}
