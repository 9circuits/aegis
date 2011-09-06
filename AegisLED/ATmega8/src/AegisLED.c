#include <stdio.h>
#include <avr/interrupt.h>

#include "lib/General.h"
#include "lib/Delay.h"
#include "lib/TWI_Slave.h"

int main (void)
	{
	uint8_t		led;
	uint8_t		status;
	uint8_t		delay;
	uint8_t		TWIS_ResonseType;

/*
** Clear any interrupt
*/
	cli ();
/*
** Wait 1 second for POR
*/
	Delay_ms (500);
	DDRD = DDRD | 0b11111100;
	DDRB = DDRB | 0b00001111;

/*
** Start TWI Slave with address 1 and bit rate of 100000 Hz
*/
	TWIS_Init (1, 100000);

	while (1)
		{
/*
** Check whether something is to do for the TWI slave interface
*/
		if (TWIS_ResonseRequired (&TWIS_ResonseType))
			{
			if(TWIS_ResonseType == TWIS_ReadBytes)
				{
/*
** Slave is requested to read bytes from the master.
** It is explicitly assumed, that the master sends 8 bytes
*/

					led = TWIS_ReadAck ();
					status = TWIS_ReadAck ();
					delay = TWIS_ReadNack ();
					TWIS_Stop ();
					if(led>=1 && led<=6)
					{	
						if(status == 1)
						{
							PORTD |= 0x01 << (led+1);
						}							
						else
						{
							if(status == 0)
							{
								PORTD &= ~(0x01 << (led+1));
							}
							else 
							{
								if (status == 2)
								{
									PORTD |= 0x01 << (led+1);
									Delay_ms (delay);
									PORTD &= ~(0x01 << (led+1));
								}
							}
						}
					}													
					else 
					{
						if(led>=7 && led<=10)
						{
							if(status == 1)
							{
								PORTB |= 0x01 << (led-7);
							}							
							else 
							{
								if (status == 0)
								{
									PORTB &= ~(0x01 << (led-7));
								}
								else
								{
									if (status == 2)
									{
										PORTB |= 0x01 << (led-7);
										Delay_ms (delay);
										PORTB &= ~(0x01 << (led-7));
									}
								}
							}
						}
						else if (led == 0)
						{
							PORTB = 0x00;
							PORTD = 0x00;
						}
					}
				}
			}
		}
	return 0;
	}
