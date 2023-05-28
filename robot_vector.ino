#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Độ rộng màn hình OLED
#define SCREEN_HEIGHT 64 // Chiều cao màn hình OLED

// Khai báo địa chỉ I2C của màn hình OLED
#define OLED_ADDR   0x3C 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Bitmap cho mắt trái
static const unsigned char eyeLeftBitmap[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0xFC, 0xFE, 0xFF, 
  0xFF, 0xFE, 0xFC, 0xF8, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Bitmap cho mắt phải
static const unsigned char eyeRightBitmap[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void setup() {
  Serial.begin(115200);

  // Khởi tạo kết nối I2C với màn hình OLED
  Wire.begin();
  
  // Khởi tạo kết nối với màn hình OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) { 
    Serial.println(F("Không tìm thấy màn hình OLED"));
    while (1);
  }

  // Xóa màn hình hiển thị
  display.clearDisplay();
}

void loop() {
  // Hiển thị mắt trái
  display.drawBitmap(0, 0, eyeLeftBitmap, 128, 64, WHITE);
  display.display();

  // Chờ 1 giây
  delay(1000);

  // Hiển thị mắt phải
  display.drawBitmap(0, 0, eyeRightBitmap, 128, 64, WHITE);
  display.display();

  // Chờ 1 giây
  delay(1000);

  // Hiển thị mắt trái và phải
  display.drawBitmap(0, 0, eyeLeftBitmap, 128, 64, WHITE);
  display.drawBitmap(0, 0, eyeRightBitmap, 128, 64, WHITE);
  display.display();

  // Chờ 1 giây
  delay(1000);
}
