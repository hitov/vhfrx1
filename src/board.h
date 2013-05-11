#ifndef _BOARD_H

/*Include board specific headers*/
#ifdef __AVR__
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#endif


/*GPIO definitions*/
#ifdef __AVR__
#define LM7001_PLL_ENABLE_DDR         (DDRD)
#define LM7001_PLL_ENABLE_PORT        (PORTD)
#define LM7001_PLL_ENABLE_BIT         (5)

#define LM7001_PLL_CLOCK_DDR          (DDRD)
#define LM7001_PLL_CLOCK_PORT         (PORTD)
#define LM7001_PLL_CLOCK_BIT          (4)

#define LM7001_PLL_DATA_DDR           (DDRB)
#define LM7001_PLL_DATA_PORT          (PORTB)
#define LM7001_PLL_DATA_BIT           (2)

#define LM7001_PLL_ENABLE_OUTPUT()    (LM7001_PLL_ENABLE_DDR  |=  (1 << LM7001_PLL_ENABLE_BIT))
#define LM7001_PLL_ENABLE_UP()        (LM7001_PLL_ENABLE_PORT |=  (1 << LM7001_PLL_ENABLE_BIT))
#define LM7001_PLL_ENABLE_DOWN()      (LM7001_PLL_ENABLE_PORT &= ~(1 << LM7001_PLL_ENABLE_BIT))

#define LM7001_PLL_CLOCK_OUTPUT()     (LM7001_PLL_CLOCK_DDR   |=  (1 << LM7001_PLL_CLOCK_BIT))
#define LM7001_PLL_CLOCK_UP()         (LM7001_PLL_CLOCK_PORT  |=  (1 << LM7001_PLL_CLOCK_BIT))
#define LM7001_PLL_CLOCK_DOWN()       (LM7001_PLL_CLOCK_PORT  &= ~(1 << LM7001_PLL_CLOCK_BIT))

#define LM7001_PLL_DATA_OUTPUT()      (LM7001_PLL_DATA_DDR    |=  (1 << LM7001_PLL_DATA_BIT))
#define LM7001_PLL_DATA_UP()          (LM7001_PLL_DATA_PORT   |=  (1 << LM7001_PLL_DATA_BIT))
#define LM7001_PLL_DATA_DOWN()        (LM7001_PLL_DATA_PORT   &= ~(1 << LM7001_PLL_DATA_BIT))

#else
#define LM7001_PLL_ENABLE_OUTPUT()
#define LM7001_PLL_ENABLE_UP()
#define LM7001_PLL_ENABLE_DOWN()

#define LM7001_PLL_CLOCK_OUTPUT()
#define LM7001_PLL_CLOCK_UP()
#define LM7001_PLL_CLOCK_DOWN()

#define LM7001_PLL_DATA_OUTPUT()
#define LM7001_PLL_DATA_UP()
#define LM7001_PLL_DATA_DOWN()
#endif

/*Delays definitions*/
#ifdef __AVR__
#define delay_us(TIME)  _delay_us(TIME);
#define delay_ms(TIME) _delay_ms(TIME)
#define dbg_printf
#else
#define delay_us(TIME)
#define delay_ms(TIME)
#define dbg_printf printf
#endif

#endif

