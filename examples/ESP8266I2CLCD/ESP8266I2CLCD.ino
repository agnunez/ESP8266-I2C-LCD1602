

  // ESP8266 with 20x4 i2c LCD
  // Compatible with the Arduino IDE 1.6.4
  // Library https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
  // Bavensky :3
  // Modified for ESP8266 with GPIO0-SDA GPIO2-SCL and LCD1206 display
  // edit library and change Wire.begin() by Wire.begin(0,2) or other GPIO's used for I2C
  
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
  
  LiquidCrystal_I2C lcd(0x27,16,2); 
  
  uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};
  
  void setup()  {
    lcd.begin(0,2);                     
    lcd.backlight();
    lcd.createChar(1, heart);
  }
  
  void loop()  {
    lcd.home();
    lcd.print("ESP8266");
    lcd.setCursor(10, 0);
    lcd.write(byte(1));
    lcd.setCursor(0, 1);
    lcd.print("LiquidCrystalI2C");
  }
