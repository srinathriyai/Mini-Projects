// ESP32 Test Bench Firmware for LABVIEW MINI PROJECT
// updated 4/16/26
// Outputs CSV over Serial: timestamp_ms, hall_raw, touch_value, adc_mv
// Baud: 115200 | Rate: 10Hz

#define TOUCH_PIN   T0   // GPIO4 — touch a wire to this
#define ADC_PIN     34   // Wire a 10k voltage divider here (3.3V → 10k → GPIO34 → 10k → GND)
#define LED_PIN     2    // Onboard LED, mirrors touch state

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  delay(500);
  Serial.println("timestamp_ms,hall_raw,touch_value,adc_mv");  // header
}

void loop() {
  uint32_t ts       = millis();
  int      hall     = random(0, 100);
 // int      hall     = hallRead();           // internal hall effect sensor
  int      touch    = touchRead(TOUCH_PIN); // lower = touched
  int      adc_raw  = analogRead(ADC_PIN);  // 0–4095
  int      adc_mv   = (adc_raw * 3300) / 4095;  // convert to millivolts

  digitalWrite(LED_PIN, touch < 40);       // LED on when touched

  Serial.print(ts);      Serial.print(",");
  Serial.print(hall);    Serial.print(",");
  Serial.print(touch);   Serial.print(",");
  Serial.println(adc_mv);

  delay(100);  // 10 Hz
}   
