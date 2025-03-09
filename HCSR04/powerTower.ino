/*
  Este código controla um sistema de sensores ultrassônicos e um servo motor em um robô.
  O robô possui um sensor ultrassônico frontal que mede a distância para um objeto à sua frente.

  Funcionalidade:
  - O código monitora a distância medida pelo sensor ultrassônico frontal.
  - Quando a distância medida pelo sensor for igual a 10 cm, um servo motor será acionado para rotacionar 180 graus.
  - O servo pode ser utilizado para controlar um mecanismo, como uma "power tower", que executa uma ação quando a distância atinge o valor desejado.
  
  A comunicação serial é utilizada para depuração, exibindo as distâncias medidas e confirmando a rotação do servo.

  Observações:
  - O servo motor é controlado utilizando a biblioteca `Servo.h`, que permite movimentar o servo entre 0° e 180°.
  - Certifique-se de que o servo esteja conectado corretamente à placa para garantir seu funcionamento adequado.
*/

#include <HCSR04.h>
#include <Servo.h>

// Definindo os pinos do sensor ultrassônico e do servo
UltraSonicDistanceSensor sensorFrente(45, 44);
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
  distace = sensorFrente.measureDistanceCm();  // Medindo a distância do sensor

  // Imprimindo a distância medida no monitor serial para depuração
  Serial.print("Distância: ");
  Serial.println(distace);

  // Quando a distância for igual a 10 cm, rotaciona o servo para 180°
  if (distace == alvo) {
    Serial.println("Distância igual a 10 cm! Rotacionando o servo...");
    powerTowerServo.write(180);  // Rotaciona o servo para 180°
    delay(1000);  // Atraso para manter o servo nessa posição por 1 segundo
  } 
  else {
    powerTowerServo.write(0);  // Caso contrário, rotaciona o servo para 0° (posição inicial)
  }

  delay(500);  // Atraso para ler a distância novamente
}
