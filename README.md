# ArduSim project
This project contains two different devices based on Arduino boards for racing (and other) simulators. The first one is the ArduSim Controller, which includes an analog handbrake, a sequential shifter, and additional custom buttons. The second one is the ArduSim Feedback device, which receives telemetry data from games via SimHub software and USB serial communication. It processes this data to control a display (gear, speed), LEDs (RPM), servos (wind direction), and a BLDC motor (wind simulator). With this method of communication, you can play with any telemetry that SimHub provides from the game and build your own feedback device based on various data.

## ArduSim Controller (works without SimHub, as a joystick/gamepad controller)
Based on an Arduino Leonardo/Pro Mini board (important! Other boards may not work properly as a USB HID device or may require additional configuration). Works through joystick arduino library like a normal joystick/gamepad device.
### Functions of controller
- Analog handbrake
- Sequential shifter
- Additional button

### Note: 
If the buttons don't work properly (maybe you are using a different type of microswitch?), try changing INPUT_PULLUP in the code to simply INPUT.
  
### Costs of controler hardware, total: 255 CZK / ~11 USD
Arduino Leonardo Pro mini: 220 CZK / ~9 USD
https://www.hadex.cz/m381b-klon-arduino-leonardo-pro-micro-atmega32u4-16mhz/

2 pcs of microswitch (or more): 30 CZK / ~1 USD
https://www.hadex.cz/l400-mikrospinac-s-packou-msw-03-on-on-1pol250v10a/ - Or you can use any microswitch from old devices (e.g., a PC mouse, a microwave door switch, etc.).

Linear potenciometer (any value should work): 5 CZK / ~0.2 USD
https://www.hadex.cz/h363-100kn-telpod-svp-30--potenciometr-tahovy/ - Or you can use a classic knob potentiometer (the mapping is the same as for a linear potentiometer), but you must solve the gear mechanism between the handle and the turning potentiometer.

And some wires, Faston connectors, a tension spring for the handbrake (or a rubber band – I used an old spring shock absorber from an RC car model), a threaded rod, and nuts for the construction. You can print a 3D model or make it your own way.

## ArduSim Feedback device (uses SimHub (or similar) as a serial device)
Based on an Arduino Nano board, but it should work with any other board that has PWM pins. The device receives data from game telemetry through SimHub serial communication, and the Arduino processes it. The easiest way to create feedback for your gaming experience.
### Functions of Feedback device
- TM1638 module with an 8-digit 7-segment display, 8 LEDs, and buttons
- LED bar displaying real-time RPM
- 7-segment display showing current speed and gear
- Mapping of 8 TM1638 buttons for in-game functions
- High-power BLDC motor with ESC unit (wind simulator)
- SG90 servo for wind direction control (air channel flap)
- TODO: Vibration pad under the brake pedal (or some kind of braking feedback)
- TODO: Heavy-duty positioning motors for full-motion rig (position potenciometers included)
   
### Costs of Feedback device, total: 735 CZK / ~30.4 USD
Arduino Nano: 139 CZK / ~5.7 USD
https://www.hadex.cz/m380c-nano-v30-r3-atmega328p-klon-arduino-s-ch340g/

Arduino Nano Shield (optional - its easy to use with servos): 38 CZK / ~1.5 USD
https://www.hadex.cz/m380e-rozsirovaci-deska---shield-pro-arduino-nano/

TM1638 8 7-segment units, 8 leds and buttons: 77 CZK / ~3.2 USD
https://www.hadex.cz/m563-ovladaci-panel-tm1638-pro-arduino/
  
BLDC high speed motor 930kV/135W: 165 CZK / ~6.8 USD
https://www.hadex.cz/l741a-motor-a221215t-bezkartacovy-outrunner-930kv/

ESC BLDC driver 30A: 260 CZK / ~10.8 USD
https://www.hadex.cz/m559a-regulator-otacek-pro-bezkartacove-motory-30a-xxd-hw30a/

Servo SG90: 56 CZK / ~2.3 USD
https://www.hadex.cz/l759-servo-plastove-sg90-180-9g-prevody-z-nylonu/

