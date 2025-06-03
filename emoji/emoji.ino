#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "_6612607769569_ezgif_com_video_to_gif_converter__1_.h" // file bạn tải lên

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // địa chỉ OLED là 0x3C
    Serial.println(F("OLED không tìm thấy!"));
    for (;;);
  }
  display.clearDisplay();
  display.display();
}

void loop() {
  for (uint16_t i = 0; i < _6612607769569_EZGIF_COM_VIDEO_TO_GIF_CONVERTER__1__FRAME_COUNT; i++) {
    display.clearDisplay();
    const uint8_t *frame = _6612607769569_ezgif_com_video_to_gif_converter__1__frames[i];
    
    for (uint16_t y = 0; y < SCREEN_HEIGHT; y++) {
      for (uint16_t x = 0; x < SCREEN_WIDTH; x++) {
        uint16_t byteIndex = y * ((SCREEN_WIDTH + 7) / 8) + (x / 8);
        uint8_t bitIndex = 7 - (x % 8);
        if (frame[byteIndex] & (1 << bitIndex)) {
          display.drawPixel(x, y, WHITE);
        }
      }
    }

    display.display();
    delay(_6612607769569_ezgif_com_video_to_gif_converter__1__delays[i]);
  }
}
