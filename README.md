# ArduSim project
This project contains two different devices based on Arduino boards for racing (and other) simulators. The first one is the ArduSim Controller, which includes an analog handbrake, a sequential shifter, and additional custom buttons. The second one is the ArduSim Feedback device, which receives telemetry data from games via SimHub software and USB serial communication. It processes this data to control a display (gear, speed), LEDs (RPM), servos (wind direction), and a BLDC motor (wind simulator).

## ArduSim Controller (works without SimHub)
Based on an Arduino Leonardo/Pro Mini board (important! Other boards may not work properly as a USB HID device or may require additional configuration).
### Functions of controller
- Analog handbrake
- Sequential shifter
- Additional button
  
### Costs of controler hardware, total: 255 CZK / ~11 USD
Arduino Leonardo Pro mini: 220 CZK / ~9 USD
https://www.hadex.cz/m381b-klon-arduino-leonardo-pro-micro-atmega32u4-16mhz/

2 pcs of microswitch (or more): 30 CZK / ~1 USD
https://www.hadex.cz/l400-mikrospinac-s-packou-msw-03-on-on-1pol250v10a/

Linear potenciometer (any value should work): 5 CZK / ~0.2 USD
https://www.hadex.cz/h363-100kn-telpod-svp-30--potenciometr-tahovy/

and some wires, Faston connectors, tension spring for handbrake (or rubber band - I use old spring shock absorber from RC car model), threaded rod and nuts for construction. You can printed 3D model or make it your own way.

## ArduSim Feedback device (uses SimHub)
Based on an Arduino Nano board, but it should work on any other board with PWM pins.
### Functions of Feedback device
- TM1638 module with an 8-digit 7-segment display, 8 LEDs, and buttons
- LED bar displaying real-time RPM
- 7-segment display showing current speed and gear
- Mapping of 8 TM1638 buttons for in-game functions
- High-power BLDC motor with ESC unit (wind simulator)
- SG90 servo for wind direction control (air channel flap)
- TODO: Vibration pad under the brake pedal
- TODO: Heavy-duty positioning motors for full-motion rig
   
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

