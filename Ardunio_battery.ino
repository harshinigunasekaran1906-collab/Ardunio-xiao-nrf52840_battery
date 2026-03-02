/* -------- Arduino Battery Voltage Read (Correct & Simple) -------- */

#define BATTERY_PIN A0

// Voltage divider resistors
#define R1 10000.0   // 10k (top)
#define R2 10000.0   // 10k (bottom)

// Arduino ADC
#define ADC_MAX 1023.0
#define ADC_REF 5.0   // Arduino UNO reference voltage

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Arduino Battery Voltage Monitor Ready");
}

void loop() {

  // Take average for stable reading
  long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += analogRead(BATTERY_PIN);
    delay(2);
  }
  float adcValue = sum / 20.0;

  // Voltage at A0
  float pinVoltage = (adcValue * ADC_REF) / ADC_MAX;

  // Original battery voltage
  float batteryVoltage = pinVoltage * ((R1 + R2) / R2);

  // Serial output
  Serial.print("ADC: ");
  Serial.print(adcValue);
  Serial.print(" | A0 Voltage: ");
  Serial.print(pinVoltage, 3);
  Serial.print(" V | Battery Voltage: ");
  Serial.print(batteryVoltage, 2);
  Serial.println(" V");

  delay(1000);
}