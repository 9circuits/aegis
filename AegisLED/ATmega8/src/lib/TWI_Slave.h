#ifndef TWI_SLAVE_H_
#define TWI_SLAVE_H_

#define	TWIS_ReadBytes		0x60
#define	TWIS_WriteBytes		0xA8
#ifndef F_CPU
#define F_CPU 8000000
#endif 
/****************************************************************************
  Public Function definitions
****************************************************************************/
uint8_t	TWIS_Init (uint8_t Address, uint32_t Bitrate);
void	TWIS_Stop (void);
uint8_t	TWIS_ReadAck (void);
uint8_t	TWIS_ReadNack (void);
uint8_t	TWIS_ResonseRequired (uint8_t *TWI_ResonseType);

#endif /* TWI_SLAVE_H_ */
