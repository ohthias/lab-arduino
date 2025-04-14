#include <afstandssensor.h>
#define LED_PIN 12
AfstandsSensor afstandssensor(6, 7);

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  Serial.begin(9600);
}

void loop() {
  if(afstandssensor.afstandCM() < 2) {
    Serial.println(afstandssensor.afstandCM());
  } else if(afstandssensor.afstandCM() <= 10) {
    blinkLed();
  } else {
    Serial.println(afstandssensor.afstandCM());
  }
}

void blinkLed() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}