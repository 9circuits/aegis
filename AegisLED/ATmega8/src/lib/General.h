#ifndef GENERAL_H_

#define GENERAL_H_

#define	TRUE	1
#define	FALSE	0
/*
** Here are some definitions, used in all programs
*/
#define SYSCLOCK				8000000	// Quartz Frequency in Hz


#define SET_BIT(PORT, BITNUM)	((PORT) |= (1<<(BITNUM)))
#define CLEAR_BIT(PORT, BITNUM) ((PORT) &= ~(1<<(BITNUM)))
#define TOOGLE_BIT(PORT,BITNUM) ((PORT) ^= (1<<(BITNUM)))


struct BitsOfByte 
	{
	uint8_t b0:1;
	uint8_t b1:1;
	uint8_t b2:1;
	uint8_t b3:1;
	uint8_t b4:1;
	uint8_t b5:1;
	uint8_t b6:1;
	uint8_t b7:1;
	} __attribute__((__packed__));


#define SBIT(port,pin) ((*(volatile struct BitsOfByte*)&port).b##pin)

#endif
