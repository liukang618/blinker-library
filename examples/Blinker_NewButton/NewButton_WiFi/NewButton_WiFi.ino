#define BLINKER_PRINT Serial
#define BLINKER_WIFI

#include <Blinker.h>

char ssid[] = "Your WiFi network SSID or name";
char pswd[] = "Your WiFi network WPA password or WEP key";

#define BUTTON_1 "ButtonKey"

BlinkerButton Button1(BUTTON_1);

void button1_callback(const String & state)
{
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    BLINKER_LOG2("get button state: ", state);

    Button1.icon("icon_1");
    Button1.iconColor("#FFFFFF");
    Button1.text("Your button name or describe");
    Button1.print("on");
}

void setup()
{
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Blinker.begin(ssid, pswd);

    Button1.attach(button1_callback);
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
