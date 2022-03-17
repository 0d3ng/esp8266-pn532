#include <Arduino.h>
#include <PN532.h>
#define SPI_MODE

#ifdef SPI_MODE
#include <SPI.h>
#include <PN532_SPI.h>
PN532_SPI pn532spi(SPI, D0);
PN532 nfc(pn532spi);
#else
#include <Wire.h>
#include <PN532_I2C.h>
PN532_I2C pn532_i2c(Wire);
PN532 nfc(pn532_i2c);
#endif

void setup()
{
  Serial.begin(115200);

  Serial.println("Hello!");

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata)
  {
    Serial.print("Didn't find PN53x board");
    while (1)
      ; // halt
  }
  // Got ok data, print it out!
  Serial.print("Found chip PN5");
  Serial.println((versiondata >> 24) & 0xFF, HEX);
  Serial.print("Firmware ver. ");
  Serial.print((versiondata >> 16) & 0xFF, DEC);
  Serial.print('.');
  Serial.println((versiondata >> 8) & 0xFF, DEC);

  // configure board to read RFID tags
  nfc.SAMConfig();

  Serial.println("Waiting for an ISO14443A Card ...");
}

void loop()
{
  // put your main code here, to run repeatedly:
}