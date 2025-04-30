#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_C4 262 

#define VIBRATION_SENSOR_PIN A5
#define BUZZER_PIN 10

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  pinMode(VIBRATION_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int sensorValue = digitalRead(VIBRATION_SENSOR_PIN);

    if (sensorValue == HIGH) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(BUZZER_PIN, melody[thisNote], noteDuration);
      delay(noteDuration);
      noTone(BUZZER_PIN);
    }
  }
}
