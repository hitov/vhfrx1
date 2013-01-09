#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
    DDRC = 0x06;
    PORTC = 0;
    for(;;)
    {
    }
    return 0;
}
