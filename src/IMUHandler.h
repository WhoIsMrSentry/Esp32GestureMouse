#ifndef IMU_HANDLER_H
#define IMU_HANDLER_H

#include <MPU6050.h>

class IMUHandler {
private:
    MPU6050 mpu;

public:
    IMUHandler();
    void initialize();
    void getMotion(int16_t &ax, int16_t &ay, int16_t &az, int16_t &gx, int16_t &gy, int16_t &gz);
};

#endif