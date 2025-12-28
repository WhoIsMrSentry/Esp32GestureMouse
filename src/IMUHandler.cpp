#include "IMUHandler.h"
#include <Wire.h>
#include <Arduino.h>

IMUHandler::IMUHandler() {}

void IMUHandler::initialize() {
    Wire.begin(21, 22); // SDA, SCL
    mpu.initialize();

    if (!mpu.testConnection()) {
        Serial.println("MPU6050 connection failed");
        while (1);
    }
}

void IMUHandler::getMotion(int16_t &ax, int16_t &ay, int16_t &az, int16_t &gx, int16_t &gy, int16_t &gz) {
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
}