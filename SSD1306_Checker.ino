#include <GyverOLED.h> //i will move it on generic SSD1306 library later

#define OLED_HEIGHT 64

#if OLED_HEIGHT == 64
  GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;
#else OLED_HEIGHT == 32 //if you have strange SSD1306 config
  GyverOLED<SSD1306_128x32, OLED_BUFFER> oled;
#endif

void setup() {
  oled.init();
  oled.clear();
  oled.home();  
  Wire.setClock(500000L); //overclock I2C interface
}

void loop()
{  //test 1-Fill every pixel 
  for (uint8_t y = 0; y < OLED_HEIGHT; ++y) 
  {
    for (uint8_t x = 0; x < 128; ++x) 
    {
    oled.dot(x, y, 1);
    oled.update(); // Screen update, obviously
    }
  }
}
