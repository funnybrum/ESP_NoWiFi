#include "NoWiFi.h"

void initSettings() {
    strcpy(settingsData.network.hostname, HOSTNAME);
}

SettingsData settingsData = SettingsData();
Logger logger = Logger();
Settings settings = Settings(&logger, (void*)(&settingsData), sizeof(SettingsData), initSettings);
WiFiManager wifi = WiFiManager(&logger, &settingsData.network);
SystemCheck systemCheck = SystemCheck(&logger);
WebServer webServer = WebServer(&settingsData.network, &logger, &systemCheck);

void setup()
{ 
    Serial.begin(74880);
    while (! Serial) {
        delay(1);
    }
    settings.begin();
    wifi.begin();
    webServer.begin();
    systemCheck.begin();

    wifi.connect();
}

void loop() {
    wifi.loop();
    webServer.loop();
    settings.loop();
    systemCheck.loop();

    delay(100);
}
