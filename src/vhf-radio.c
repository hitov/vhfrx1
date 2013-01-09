#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
    DDRC = 0x06;
    PORTC = 1<<1;
    for(;;)
    {
        PORTC = 1<<1;
        _delay_ms(100);
        PORTC = 2<<1;
        _delay_ms(100);
    }
    return 0;
}
