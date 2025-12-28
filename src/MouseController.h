#ifndef MOUSE_CONTROLLER_H
#define MOUSE_CONTROLLER_H

#include "HIDMouse.h"

class MouseController {
public:
    MouseController();
    void initialize();
    void move(int x, int y);
    void scroll(int value);
    void pressButton(uint8_t button);
    void releaseButton(uint8_t button);
};

#endif