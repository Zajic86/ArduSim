extern "C" {
  void setup();
  void loop();
}

#include <HardwareSerial.h>
#include <TM1638.h>
#include <Servo.h>
#include <Arduino.h>

#define DATA 5
#define CLOCK 6
#define STROBE 4

TM1638 module(DATA, CLOCK, STROBE);
Servo esc;
Servo flapServo;

int gear = 0;    // Gear level
int speed = 0;   // Speed in km/h
int rpm = 0;     // RPM (Revolutions Per Minute)
int maxRPM = 8000;   // Default max RPM of the car
float yaw = 0;   // Car orientation (steering - yaw)
bool dataReceived = false;  // Indicator if data has been received

void setup() {
  Serial.begin(115200);
  esc.attach(9);
  esc.writeMicroseconds(1000);  // Initialize ESC to minimum value (motor stopped)
  flapServo.attach(10);
  flapServo.write(90);          // Center the flap
  module.clearDisplay();
  module.setupDisplay(true, 3);
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');  // Read a line from SimHub

    int firstSep = data.indexOf(';');
    int secondSep = data.indexOf(';', firstSep + 1);
    int thirdSep = data.indexOf(';', secondSep + 1);
    int fourthSep = data.indexOf(';', thirdSep + 1);

    if (firstSep != -1 && secondSep != -1 && thirdSep != -1 && fourthSep != -1) {
      gear  = data.substring(0, firstSep).toInt();              // Current gear
      speed = data.substring(firstSep + 1, secondSep).toInt();  // Current speed
      rpm   = data.substring(secondSep + 1, thirdSep).toInt();  // Current RPM
      maxRPM = data.substring(thirdSep + 1, fourthSep).toInt(); // Max RPM of the vehicle (used for RPM gauge mapping)
      yaw   = data.substring(fourthSep + 1).toFloat(); // Last value is Yaw (steering)
      
      // If all values are zero, it means data is invalid
      if (speed == 0 && rpm == 0 && gear == 0 && yaw == 0) {
        dataReceived = false;  // Zero data -> waiting for valid data
        esc.writeMicroseconds(1000);
      } else {
        dataReceived = true;  // Valid data received -> process it
      }
    }
  }

if (dataReceived) {
  // Display speed on the TM1638 module
  module.setDisplayToDecNumber(speed, 0, false);

  // LED indicator for RPM (max 8 LEDs at 7000 RPM)
  int ledCount = map(rpm, 0, maxRPM, 0, 8); // Map RPM to LED count
  byte ledPattern = (1 << ledCount) - 1;       // Create bitmask for LEDs
  module.setLEDs(ledPattern);                   // Set LEDs based on RPM

  // Display gear number on the last segment
  module.setDisplayDigit(gear, 3, false);

  // ESC control based on speed
  // Map speed (50 - 300 km/h) to PWM value for ESC (1000 - 2000 µs)
  int escValue = map(speed, 50, 300, 1125, 1300);  // Speed in km/h -> PWM pulse for ESC
  esc.writeMicroseconds(escValue);  // Set motor value

  // Servo control based on steering (Yaw)
  int servoAngle = map(yaw, -30, 30, 0, 180); // Yaw -30° to 30° -> 0° to 180°
  servoAngle = constrain(servoAngle, 0, 180); // Limit within servo range
  flapServo.write(servoAngle);
} 
else {
    // Display text when no valid data is received
    module.setDisplayToString("ZAJIC86");  // Set text on display
    module.setLEDs(0x00);  // Turn off LEDs
    esc.writeMicroseconds(1000);
  }
}
