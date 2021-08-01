#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "Activity1.h"
#include "Activity2.h"
#include "Activity3.h"



int main(void)
{
    inisialise_ports();
    InitADC();
    uint16_t temp=0;
    uint16_t tempdata=0;
    setupADC();

    while(1)
          {
              if(CHECKSEAT)
              {
                    PORTB|=(1<<PB0);
                    _delay_ms(20);

                    temp= ReadADC(0);
                    _delay_ms(200);

                    tempdata=pwmout(temp);
                    _delay_ms(20);


              }
               else
                {
                    PORTB&=~(1<<PB0);
                    _delay_ms(200);
                     OCR1A = 0;
                }
          }


    return 0;
}
