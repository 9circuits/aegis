#include <AegisLED.h>
#include <Wire.h>

uint8_t i,j;
uint8_t toggle = 0;

AegisLED led;

void setup()
{
  Serial.begin(9600);
  Serial.println("Before glow:");
  led.init(1);
  delay(5000);
  Serial.println("blah");
}

void loop()
{
  for(i=1;i<=3;i++)
  {
    for(j=1;j<=10;j++)
    {
      if(toggle == 0)
      {
        led.init(i);
        led.on(j);
        Serial.print("Turning on Dev, LED: ");
        Serial.print(i, DEC);
        Serial.print(", ");
        Serial.println(j, DEC);
      }
      else
      {
        led.init(i);
        led.off(j);
        Serial.print("Turning off Dev, LED: ");
        Serial.print(i, DEC);
        Serial.print(", ");
        Serial.println(j, DEC);
      }
      delay(500);
    }
    delay(3000); //For testing
  }
  if(toggle == 0)
  {
    toggle = 1;
  }
  else
  {
    toggle = 0;
  }
}
