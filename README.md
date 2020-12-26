Note: This has been used quite some time as template for ESP82xx baed projects. There is zero progress on the NoWiFi idea yet.

# No WiFi

ESP8266/ESP8258/ESP32 are cheap microcontrollers that seems quite good for DIY IoT devices. However having a lot of them introduce an issue - EMF pollution. EMF pollution is created when there are a lot of packets flowing over the WiFi network. This project is trying to provide a solution for that problem.

The idea - the ESPxx can register to the WiFi network and go offline. In this offline mode it can sniff the WiFi traffic. The controller will listen for ping packets send to it and do actions based on the ping packet payload. This way no EMF pollution will be introduced (except when the controller is being connected to the WiFi network). If this is used a switch (for example) - you should be able to controll it even when it is disconnected from the WiFi network.

This is currently just an idea. There is an expectation that the controller will have to reconnect on regular intervals to the network. The interval depends on the WiFi router settings - how long it will keep the DNS record and the IP address to MAC address mapping.

Example of supported commands can be:
 * Turn a device on or off.
 * Connect to the network and leave "sniff" mode.
 * Restart the controller.

And a few details how I got here - there are plenty of WiFi "smart" devices in my home (probably around 15). Most of them are collecting sensor readings (AQ monitors, power monitor) and were programmed to buffer the data in the memory of the controller and stay disconnected from the network. Once the data buffer gets full (or on regular intervals) the controller reconnects to the WiFi network and sends the data directly to an InfluxDB. However this introduced a complication - if I want to re-flash a device I don't have an easy mechanism to instruct it to turn its WiFi on. And this is how the idea was borned.

## Building the project

The project uses a common set of tools that are availabe in another repo - https://github.com/funnybrum/esp8266-base. Clone the esp8266-base repo in the lib folder:

```
cd lib
git clone git@github.com:funnybrum/esp8266-base.git
```

Actually the changes should become part of the esp8266-base project. This introduces only the required files to enable the development of the POC. Once done all details about this will be documented in the esp8266-base project.
