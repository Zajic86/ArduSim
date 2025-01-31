#include <Joystick.h>

const int pinThrottle = A0;
const int buttonShiftUp = 2;
const int buttonShiftDown = 3;
const int button1 = 4;

int lastThrottleValue = -1; // Last handbrake value

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,
                   8, 0,                   // 8 buttons, no axis
                   false, false, false,    // X, Y, Z no
                   false, false, false,    // RX, RY, RZ no
                   true, false,            // Throttle YES, Rudder NO
                   false, false, false);   // No other axis


void setup()
{
    pinMode(pinThrottle, INPUT);
    pinMode(buttonShiftUp, INPUT_PULLUP);
    pinMode(buttonShiftDown, INPUT_PULLUP);
    pinMode(button1, INPUT_PULLUP);
    Joystick.begin();
    Serial.begin(9600);
    Serial.print("Starting ArduSim Controller...");
}

void loop()
{

    // ANALOG HANDBRAKE
    int potValue = analogRead(pinThrottle);
    int throttleValue = map(potValue, 0, 1023, 0, 255);

    if (throttleValue != lastThrottleValue)
    {
        Joystick.setThrottle(throttleValue);
        lastThrottleValue = throttleValue;
    }

    // SHIFT UP
    int currentButtonUpState = digitalRead(buttonShiftUp);
    if (currentButtonUpState == LOW)
    {
        Joystick.pressButton(6);
        delay(10);
    }

    if (currentButtonUpState == HIGH)
    {
        Joystick.releaseButton(6);
        delay(10);
    }

    // SHIFT DOWN
    int currentButtonDownState = digitalRead(buttonShiftDown);
    if (currentButtonDownState == LOW)
    {
        Joystick.pressButton(7);
        delay(10);
    }
    if (currentButtonDownState == HIGH)
    {
        Joystick.releaseButton(7);
        delay(10);
    }

    // BUTTON 1
    int currentButton1State = digitalRead(button1);
    if (currentButton1State == LOW)
    {
        Joystick.pressButton(8);
        delay(10);
    }
    if (currentButton1State == HIGH)
    {
        Joystick.releaseButton(8);
        delay(10);
    }
}
