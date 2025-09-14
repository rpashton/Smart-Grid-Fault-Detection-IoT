#include <Arduino.h>

const int currentSensorPin = A0; // ACS712
const int voltageSensorPin = A1; // Voltage divider

float voltage = 0.0;
float current = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Simulated sensor readings
  int rawCurrent = analogRead(currentSensorPin);
  int rawVoltage = analogRead(voltageSensorPin);

  // Convert to real values 
  voltage = (rawVoltage * 5.0 / 1023.0) * 100; // scale factor
  current = ((rawCurrent - 512) * 5.0 / 1023.0) * 20; // ACS712 20A

  // Fault detection thresholds
  bool fault = false;
  if (voltage < 180 || voltage > 250) {
    fault = true;
    Serial.println("⚠ Voltage Fault Detected");
  }
  if (current > 15.0) {
    fault = true;
    Serial.println("⚠ Overcurrent Fault Detected");
  }

  // Print readings
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V | Current: ");
  Serial.print(current);
  Serial.println(" A");

  if (!fault) {
    Serial.println("✓ System Normal");
  }

  delay(1000); // 1 second refresh
}
