#include <avr/io.h>
#include "Activity1.h"

void inisialise_ports()
{
    DDRB|=(1<<PB0);
    DDRD&=~(1<<PD2);
    PORTD|=(1<<PD2);
    DDRD&=~(1<<PD3);
    PORTD|=(1<<PD3);
}
