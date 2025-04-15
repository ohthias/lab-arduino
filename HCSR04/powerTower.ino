/*
  Este código controla um sistema de sensores ultrassônicos e um servo motor em um robô.
  O robô possui um sensor ultrassônico frontal que mede a distância para um objeto à sua frente.

  Funcionalidade:
  - O código monitora a distância medida pelo sensor ultrassônico frontal.
  - Quando a distância medida pelo sensor for igual a 10 cm, um servo motor será acionado para rotacionar 180 graus.
  - O servo pode ser utilizado para controlar um mecanismo, como uma "power tower", que executa uma ação quando a distância atinge o valor desejado.
*/

#include <HCSR04.h>
#include <Servo.h>

UltraSonicDistanceSensor sensorFrente(2, 3);
Servo powerTowerServo;

int distace;
int alvo = 10;  // Distância alvo para acionar o servo
int servoPin = 9;  // Pino onde o servo está conectado

void setup() {
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
  powerTowerServo.attach(servoPin);  // Conectando o servo ao pino especificado
}

void loop() {
  distace = sensorFrente.measureDistanceCm(); 

  Serial.print("Distância: ");
  Serial.println(distace);

  if (distace == alvo) {
    Serial.println("Distância igual a 10 cm! Rotacionando o servo...");
    powerTowerServo.write(180);
    delay(1000);
  } 
  else {
    powerTowerServo.write(0);
  }

  delay(500);
}
