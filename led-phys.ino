#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void setup() {
  Serial.begin(115200);
  matrix.begin();
};
uint32_t y = 0x80000000;

// Direction | positive means increase the number by 2
bool velocity_positive = false;
uint32_t frame_buffer[] = {
  y,
  0x0,
  0x0
};
void loop() {
  // 0x200000 is the last LED in the first row
  if (y <= 0x100000) {
    velocity_positive = true;
    // We've reached the first LED
  } else if (y >= 0x80000000) {
    velocity_positive = false;
  }

  frame_buffer[0] = y;
  matrix.loadFrame(frame_buffer);
  delay(100);

  if (velocity_positive) {
    y = y * 2;
  } else {
    y = y / 2;
  }
};