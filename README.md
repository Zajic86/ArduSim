# ArduSim project
Arduino projects for racing (and other) simulators. The controller uses the Joystick library, making it easy to use—just plug and play. Feedback device must be added as a custom serial device in SimHub for telemetry data.

# ArduSim Controller (works without SimHub)
Based on an Arduino Leonardo/Pro Mini board (important! Other boards may not work properly as a USB HID device or may require additional configuration).
- Analog handbrake
- Sequential shifter
- Additional button

# ArduSim Feedback device (uses SimHub)
Based on an Arduino Nano board, but it should work on any other board with PWM pins.
- TM1638 module with an 8-digit 7-segment display, 8 LEDs, and buttons
- LED bar displaying real-time RPM
- 7-segment display showing current speed and gear
- Mapping of 8 TM1638 buttons for in-game functions
- High-power BLDC motor with ESC unit (wind simulator)
- SG90 servo for wind direction control (air channel flap)
- Vibration pad under the brake pedal
- Heavy-duty positioning motors for full-motion rig

  
