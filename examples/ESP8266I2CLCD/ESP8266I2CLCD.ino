// ESP8266 with 20x4 i2c LCD
// Compatible with the Arduino IDE 1.6.6
// Current Library https://github.com/agnunez/ESP8266-I2C-LCD1602
// Original Library https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
// Agustin Nunez Dec 2015
// Modified for ESP8266 with GPIOx->SDA GPIOx->SCL and LCD1206 display
// edit library and change Wire.begin() by Wire.begin(0,2) or other GPIO's used for I2C
  
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
  
  LiquidCrystal_I2C lcd(0x27,16,2); // Check I2C address of LCD, normally 0x27 or 0x3F
  
  uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};  // example sprite bitmap
  
  void setup()  {
    lcd.begin(0,2);      // In ESP8266-01, SDA=0, SCL=2               
    lcd.backlight();
    lcd.createChar(1, heart);
  }
  
  void loop()  {
    lcd.home();                // At column=0, row=0
    lcd.print("ESP8266");   
    lcd.setCursor(0, 1);
    lcd.print("LiquidCrystalI2C");
    delay(500);
    lcd.setCursor(10, 0);      // At column=10, row=0
    lcd.write(byte(1));
    delay(500);
    lcd.setCursor(10, 0);      // At column=10, row=0
    lcd.print(" ");            // Wipe sprite
  }
