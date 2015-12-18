  // ESP8266 with 16x2 i2c LCD
  // Compatible with the Arduino IDE 1.6.6
  // Library https://github.com/agnunez/ESP8266-I2C-LCD1602
  // Original Library https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
  // Modified for ESP8266 with GPIO0-SDA GPIO2-SCL and LCD1206 display
  // edit library and change Wire.begin() by Wire.begin(sda,scl) or other GPIO's used for I2C
  // and access from lcd.begin(sda,scl)
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
	// initialize the LCD
	lcd.begin(0,2);
}

void loop()
{
	bool blinking = true;
	lcd.cursor(0,2);

	while (1) {
		if (blinking) {
			lcd.clear();
			lcd.print("No cursor blink");
			lcd.noBlink();
			blinking = false;
		} else {
			lcd.clear();
			lcd.print("Cursor blink");
			lcd.blink();
			blinking = true;
		}
		delay(4000);
	}
}
