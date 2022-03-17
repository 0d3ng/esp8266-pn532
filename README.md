# esp8266-pn532
Sample wiring reader pn532 for esp8266

## Wiring SPI
ESP8266            | PN532
---------------- | ----------------------
5V               | VCC 
GND              | GND
D5 (GPIO 14)    | SCK
D6 (GPIO 12)    | MISO
D7 (GPIO 13)    | MOSI
D0 (GPIO 16)      | SS

## Wiring I2C
ESP8266            | PN532
---------------- | ----------------------
5V               | VCC 
GND              | GND
D2 (GPIO 5)    | SDA
D1 (GPIO 4)    | SCL

## How to use
Comment code ```#define SPI_MODE``` in ```main.cpp``` if using I2C mode
