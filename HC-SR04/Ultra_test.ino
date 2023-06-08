#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor (45, 44);
int distace;
int alvo = 10;
int LED_green  = 9;
int LED_redEsq = 8;
int LED_redDir = 10;


void setup () {
  pinMode(LED_green, OUTPUT);
  pinMode(LED_redEsq, OUTPUT);
  pinMode(LED_redDir, OUTPUT);
  Serial.begin(1200);
}

void loop () {
  distace = distanceSensor.measureDistanceCm();

  if (distace != alvo && distace > alvo) {
    digitalWrite(LED_green, HIGH);
    digitalWrite(LED_redDir, HIGH);
    digitalWrite(LED_redEsq, HIGH);
    delay(150);
    digitalWrite(LED_green, LOW);
    digitalWrite(LED_redDir, LOW);
    digitalWrite(LED_redEsq, LOW);
    delay(150);
    return;
  }

  if (distace <= alvo && distace > 5) {
    Serial.println(distace);
    digitalWrite(LED_green, HIGH);
    delay (100);
  }
  else if (distace < 5) {
    digitalWrite(LED_green, LOW);
    digitalWrite(LED_redDir, HIGH);
    digitalWrite(LED_redEsq, HIGH);
    delay(150);
    digitalWrite(LED_redDir, LOW);
    digitalWrite(LED_redEsq, LOW);
    delay(150);
  }
}
