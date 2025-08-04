#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_BMP280.h>
#include "notes.h"         // Contains note frequency definitions
#include "song.h"          // Contains playMegaloStrikesBack()

// Pin assignments:
const int chipSelect    = 7;   // SD card CS pin
const int buzzerPin     = 10;  // Piezo buzzer pin

Adafruit_BMP280 bmp;            // BMP280 sensor instance (I2C)

// Timing intervals (all in milliseconds):
const unsigned long logInterval   = 2000UL;   // log sensor data every 2 s
const unsigned long playInterval  = 2000UL;   // play song every 2 s (set this to 600000UL for 10 min)

unsigned long previousLogMillis   = 0;
unsigned long previousPlayMillis  = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) { delay(10); }

  // Initialize SD card
  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println(" failed!");
  } else {
    Serial.println(" done.");
  }

  // Initialize BMP280
  Serial.println("Initializing BMP280...");
  if (!bmp.begin(0x76)) {
    Serial.println("Could not find a valid BMP280 sensor!");
    while (1) delay(10);
  }
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,    // Operating Mode
                  Adafruit_BMP280::SAMPLING_X2,    // Temp oversampling
                  Adafruit_BMP280::SAMPLING_X16,   // Pressure oversampling
                  Adafruit_BMP280::FILTER_X16,     // Filtering
                  Adafruit_BMP280::STANDBY_MS_500);// Standby time

  // Initialize timers
  unsigned long now = millis();
  previousLogMillis  = now;
  previousPlayMillis = now;  // start counting for the first play
}

void loop() {
  unsigned long currentMillis = millis();

  // 1) Log sensor data every 2 s
  if (currentMillis - previousLogMillis >= logInterval) {
    previousLogMillis = currentMillis;
    logSensorData();
  }

  // 2) Play song on a repeating interval
  if (currentMillis - previousPlayMillis >= playInterval) {
    previousPlayMillis = currentMillis;
    Serial.println("Interval reached — playing song!");
    playMegaloStrikesBack(buzzerPin);
  }

  // (Other non-blocking tasks can go here)
}

void logSensorData() {
  // Read BMP280
  float temperature = bmp.readTemperature();
  float pressure    = bmp.readPressure();

  // Print to Serial
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Pressure: ");
  Serial.print(pressure);
  Serial.println(" Pa");

  // Append to SD card
  Serial.println("Saving data to SD card...");
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.print("Temperature: ");
    dataFile.print(temperature);
    dataFile.println(" °C");

    dataFile.print("Pressure: ");
    dataFile.print(pressure);
    dataFile.println(" Pa\n");

    dataFile.close();
    Serial.println("Data logged.");
  } else {
    Serial.println("Error opening datalog.txt");
  }
}
