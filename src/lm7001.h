#ifndef _LM7001_H
#define _LM7001_H

#include <stdint.h>

typedef union {
    uint8_t   data_bytes[3];
    uint32_t  data;
}lm7001_data_t;

#define LM7001_PLL_DATA_BITS       (24)

#define LM7001_PLL_DIVIDER_MASK    (0x3FFF)
#define LM7001_PLL_DIVIDER_OFFSET  (0)

#define LM7001_PLL_BAND_MASK       (0x000F)
#define LM7001_PLL_BAND_OFFSET     (16)
#define LM7001_PLL_BAND_B0         (1 << 0)
#define LM7001_PLL_BAND_B1         (1 << 1)
#define LM7001_PLL_BAND_B2         (1 << 2)
#define LM7001_PLL_BAND_TB         (1 << 3)

#define LM7001_PLL_FREF_MASK       (0x0007)
#define LM7001_PLL_FREF_OFFSET     (20)
#define LM7001_PLL_FREF_100KHZ     (0)
#define LM7001_PLL_FREF_10KHZ      (1)
#define LM7001_PLL_FREF_25KHZ      (2)
#define LM7001_PLL_FREF_1KHZ       (3)
#define LM7001_PLL_FREF_50KHZ      (4)
#define LM7001_PLL_FREF_9KHZ       (5)
#define LM7001_PLL_FREF_5KHZ       (6)

#define LM7001_PLL_INTYPE_MASK     (0x0001)
#define LM7001_PLL_INTYPE_OFFSET   (23)
#define LM7001_PLL_INTYPE_AMIN     (0)
#define LM7001_PLL_INTYPE_FMIN     (1)

#define LM7001_PLL_DATA_PREPARE(DIV, BAND, FREF, INTYPE) \
        (                                                                                  \
        ((LM7001_PLL_DIVIDER_MASK & ((uint32_t) DIV)   ) << LM7001_PLL_DIVIDER_OFFSET)   | \
        ((LM7001_PLL_BAND_MASK    & ((uint32_t) BAND)  ) << LM7001_PLL_BAND_OFFSET   )   | \
        ((LM7001_PLL_FREF_MASK    & ((uint32_t) FREF)  ) << LM7001_PLL_FREF_OFFSET   )   | \
        ((LM7001_PLL_INTYPE_MASK  & ((uint32_t) INTYPE)) << LM7001_PLL_INTYPE_OFFSET )     \
        )

/*LM7001 PLL functions declarations*/
void lm7001_init(lm7001_data_t *plldev, uint16_t divider, uint8_t band, uint8_t fref, uint8_t intype);
void lm7001_prepare_data(lm7001_data_t *plldev, uint16_t divider, uint8_t band, uint8_t fref, uint8_t intype);
void lm7001_wrire(lm7001_data_t *plldev);

/*GPIO definitions*/
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

#endif
