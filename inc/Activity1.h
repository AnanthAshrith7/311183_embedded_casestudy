#ifndef ACTIVITY1_H_INCLUDED
#define ACTIVITY1_H_INCLUDED
void inisialise_ports();
#define CHECKSEAT ((!(PIND&(1<<PD2)))&&(!(PINC&(1<<PC2))))
#endif

