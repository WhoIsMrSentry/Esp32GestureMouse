#include <BluetoothSerial.h>
#include "src/IMUHandler.h"
#include "src/MouseController.h"

BluetoothSerial SerialBT;
IMUHandler imuHandler;
MouseController mouseController;

const int leftButtonPin = 25;  // GPIO pin for left click button
const int rightButtonPin = 26; // GPIO pin for right click button

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Mouse");

  imuHandler.initialize();
  mouseController.initialize();

  pinMode(leftButtonPin, INPUT_PULLUP); // Configure left button pin
  pinMode(rightButtonPin, INPUT_PULLUP); // Configure right button pin
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  imuHandler.getMotion(ax, ay, az, gx, gy, gz);

  // Convert gyroscope values to mouse movements
  int mouseX = gx / 131;
  int mouseY = gy / 131;

  // Map these values to a suitable range for mouse movement
  mouseX = map(mouseX, -32768, 32767, -10, 10);
  mouseY = map(mouseY, -32768, 32767, -10, 10);

  // Simulate mouse movement
  mouseController.move(mouseX, mouseY);

  // Simulate scroll function (for example, using the Z-axis of the gyroscope)
  int scrollValue = gz / 131;
  scrollValue = map(scrollValue, -32768, 32767, -5, 5);
  if (scrollValue != 0) {
    mouseController.scroll(scrollValue);
  }

  // Check button states for left and right clicks
  if (digitalRead(leftButtonPin) == LOW) {
    mouseController.pressButton(HIDMouse.LEFT_BUTTON);
  } else {
    mouseController.releaseButton(HIDMouse.LEFT_BUTTON);
  }

  if (digitalRead(rightButtonPin) == LOW) {
    mouseController.pressButton(HIDMouse.RIGHT_BUTTON);
  } else {
    mouseController.releaseButton(HIDMouse.RIGHT_BUTTON);
  }

  delay(10);
}
