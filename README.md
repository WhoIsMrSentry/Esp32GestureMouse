# ESP32-IMU_MOUSE
The project developed using ESP32 and MPU6050 sensor simulates mouse movements, scroll function, and now includes left and right click functionality based on physical buttons. It communicates with other devices such as a mobile phone or computer via Bluetooth.

## Components Required:
- ESP32 (for Bluetooth communication and processing)
- MPU6050 (for capturing hand tilt/movement)
- 2 Push Buttons (for left and right click functionality)
- Wires (for connections)
- Breadboard (optional, for easy prototyping)

## Wiring:
### MPU6050 Connections:
- VCC → 3.3V on ESP32
- GND → GND on ESP32
- SCL → GPIO 22 on ESP32
- SDA → GPIO 21 on ESP32

### Button Connections:
- Left Button → GPIO 25 on ESP32 (with pull-up resistor)
- Right Button → GPIO 26 on ESP32 (with pull-up resistor)

## Step 1: Setting Up the MPU6050
The MPU6050 will be used to capture the tilt of the hand. You can obtain the accelerometer and gyroscope values to calculate the tilt.

## Step 2: Configuring Bluetooth HID on ESP32
ESP32 will be configured to act as a Bluetooth Human Interface Device (HID), which will allow it to simulate a mouse.

## Step 3: Programming the ESP32
The project has been modularized for better readability and maintainability. The code is divided into the following components:
- `IMUHandler`: Handles initialization and data retrieval from the MPU6050 sensor.
- `MouseController`: Manages mouse movements, scrolling, and button clicks.

Open the `IMU_Mouse.ino` code in the IDE to see how these components are used.

## Step 4: Flashing the Code to ESP32
1. Connect your ESP32 to your computer.
2. Upload the code using the Arduino IDE or PlatformIO.

## Step 5: Testing
1. Pair the ESP32 with your computer or mobile phone via Bluetooth. The device should show up as "ESP32_Mouse."
2. Once connected, the ESP32 will:
   - Simulate mouse movements and scrolling based on the tilt captured by the MPU6050.
   - Detect button presses for left and right clicks.

# Adjustments:
- You may need to tweak the sensitivity of the gyroscope readings and the mapping values to match your preferred movement speed and scroll sensitivity.
- Additional calibration may be required to ensure the device works correctly with your specific setup.

# Contribute
This setup allows you to simulate mouse movements, scrolling, and button clicks using the MPU6050 sensor and ESP32 over Bluetooth. Let me know if you need further customization or have any questions!
