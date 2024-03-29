#ifndef DELAY_H_
#define DELAY_H_

#include <avr/io.h>

/* mth 9/04:
   Remark uSeconds:
   Main Oscillator Clock given by F_CPU (makefile) in Hz
   one CPU-Cycle takes 1/F_CPU seconds => 1000000/F_OSC uSeconds
   so: 1 uSecond takes F_CPU/1000000 CPU-Cycles. The following code
   is inspired by the avr-libc delay_loop2 function.
   This it not "that precise" since it takes at least 4 cycles
   but should be o.k. with any parameter (even 0).
   Call function with delay loop(DELAYUS(dt [in uSeconds])).
*/

/* delay function for micro sec
   4 cpu cycles per loop + 1 cycles(?) overhead
   when a constant is passed. */
static inline void Delayloop16(uint16_t count)
{
	asm volatile (  "cp  %A0,__zero_reg__ \n\t"  \
                     "cpc %B0,__zero_reg__ \n\t"  \
                     "breq L_Exit_%=       \n\t"  \
                     "L_LOOP_%=:           \n\t"  \
                     "sbiw %0,1            \n\t"  \
                     "brne L_LOOP_%=       \n\t"  \
                     "L_Exit_%=:           \n\t"  \
                     : "=w" (count)
					 : "0"  (count)
                   );
}
// delayloop16(x) eats 4 cycles per x
#define DELAY_US_CONV(us) ((uint16_t)(((((us)*1000L)/(1000000000/F_CPU))-1)/4))
#define Delay_us(us)	  Delayloop16(DELAY_US_CONV(us))

/* delay function for milli sec
  (6 cycles per x + 20(?) overhead) */
void Delayloop32( uint32_t l); // not inline
#define DELAY_MS_CONV(ms) ( (uint32_t) (ms*(F_CPU/6000L)) )
#define Delay_ms(ms)  Delayloop32(DELAY_MS_CONV(ms))

#endif /* DELAY_H_ */
