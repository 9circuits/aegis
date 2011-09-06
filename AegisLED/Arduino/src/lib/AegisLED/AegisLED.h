#ifndef AEGISLED_H_
#define AEGISLED_H_

#include <Wire.h>
#include <inttypes.h>
#include "WProgram.h"

class AegisLED
{
	private:
		uint8_t _device_id;
	public:
		void init(uint8_t device_id);
		int on(uint8_t led_id);
		int off(uint8_t led_id);
		int glow(uint8_t led_id, uint8_t duration);
};

#endif /* AEGISLED_H_ */
