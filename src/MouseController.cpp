#include "MouseController.h"

MouseController::MouseController() {}

void MouseController::initialize() {
    HIDMouse.begin();
}

void MouseController::move(int x, int y) {
    HIDMouse.move(x, y);
}

void MouseController::scroll(int value) {
    HIDMouse.scroll(value);
}

void MouseController::pressButton(uint8_t button) {
    HIDMouse.press(button);
}

void MouseController::releaseButton(uint8_t button) {
    HIDMouse.release(button);
}