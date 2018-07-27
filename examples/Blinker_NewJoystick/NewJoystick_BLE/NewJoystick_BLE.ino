#define BLINKER_PRINT Serial
#define BLINKER_BLE

#include <Blinker.h>

void joystick_callback(uint8_t xAxis, uint8_t yAxis)
{
    BLINKER_LOG2("Joystick X axis: ", xAxis);
    BLINKER_LOG2("Joystick Y axis: ", yAxis);
}

void setup()
{
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Blinker.begin();

    Joystick.attach(joystick_callback);
}

void loop()
{
    Blinker.run();

    if (Blinker.available()) {
        BLINKER_LOG2("Blinker.readString(): ", Blinker.readString());

        Blinker.vibrate();
        
        uint32_t BlinkerTime = millis();
        Blinker.print(BlinkerTime);
        Blinker.print("millis", BlinkerTime);
    }
}
