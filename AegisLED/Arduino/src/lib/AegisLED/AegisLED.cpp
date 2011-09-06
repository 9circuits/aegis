#include <Wire.h>
#include <inttypes.h>
#include "WProgram.h"
#include <AegisLED.h>

void AegisLED::init(uint8_t device_id)
{
	_device_id = device_id;
    Wire.begin();
}

int AegisLED::on(uint8_t led_id)
{
	Wire.beginTransmission(_device_id);
	Wire.send(led_id);
	Wire.send(0x01);
	Wire.send(0x00);
	return Wire.endTransmission();
}

int AegisLED::off(uint8_t led_id)
{
	Wire.beginTransmission(_device_id);
	Wire.send(led_id);
	Wire.send(0x00);
	Wire.send(0x00);
	return Wire.endTransmission();
}

int AegisLED::glow(uint8_t led_id, uint8_t duration)
{
	Wire.beginTransmission(_device_id);
	Wire.send(led_id);
	Wire.send(0x02);
	Wire.send(duration);
	return Wire.endTransmission();
}
