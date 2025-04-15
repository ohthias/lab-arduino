/*
  Este código controla um sistema de sensores ultrassônicos em um robô. 
  O robô possui três sensores ultrassônicos para medir a distância: um na frente e dois nas laterais (esquerda e direita).
  
  O objetivo principal do código é monitorar a distância medida por esses sensores e acionar LEDs conforme o valor da distância.
  O código também verifica o estado de um botão (BTN_f4) para alternar entre estados de LED.

  Funcionalidade:
  - Quando o botão BTN_f4 for pressionado (estado HIGH), todos os LEDs acendem por 150 ms e depois se apagam, como um efeito de piscar.
  - Quando o botão não estiver pressionado, o robô verifica a distância dos sensores:
  - Se o sensor frontal medir uma distância dentro de um valor pré-definido (`alvo`), o LED verde acende.
  - Se a distância do sensor lateral esquerdo for menor que o valor `alvo`, o LED vermelho esquerdo acende. Se o sensor lateral direito for o que está mais próximo do alvo, o LED vermelho direito acende.
  - Caso a distância frontal seja muito curta (< 5 cm), os LEDs vermelhos piscam alternadamente para indicar proximidade.
*/

#include <HCSR04.h>

UltraSonicDistanceSensor sensorFrente(2, 3);
UltraSonicDistanceSensor sensorEsq(4, 5);
UltraSonicDistanceSensor sensorDir(6, 7);

int distancia, distanciaLatEsq, distanciaLatDir;
int alvo = 10;

// Definição dos LEDs
int LED_green = 10;
int LED_redEsq = 11;
int LED_redDir = 12;

// Definição do botão
int BTN_f4 = 8;
int estadoBtn = 0;

void setup() {
  pinMode(LED_green, OUTPUT);
  pinMode(LED_redEsq, OUTPUT);
  pinMode(LED_redDir, OUTPUT);
  pinMode(BTN_f4, INPUT);
  Serial.begin(1200);
}

void loop() {
  distancia = sensorFrente.measureDistanceCm();
  distanciaLatEsq = sensorEsq.measureDistanceCm();
  distanciaLatDir = sensorDir.measureDistanceCm();
  estadoBtn = digitalRead(BTN_f4);
  
  if (estadoBtn == HIGH) {
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

  if (estadoBtn == LOW) {
    if (distancia <= alvo && distancia > 5) {
      Serial.println(distancia);
      digitalWrite(LED_green, HIGH);

      if (distanciaLatEsq <= alvo && distanciaLatEsq > 4) {
        Serial.print(distanciaLatEsq);
        digitalWrite(LED_redEsq, HIGH);
        delay(100);
      } 
      else if (distanciaLatDir <= alvo && distanciaLatDir > 4) {
        Serial.print(distanciaLatDir);
        digitalWrite(LED_redDir, HIGH);
        delay(100);
      } 
      else {
        digitalWrite(LED_redDir, LOW);
        digitalWrite(LED_redEsq, LOW);
        delay(100);
      }
    } 
    else if (distancia < 5) {
      digitalWrite(LED_green, LOW);
      digitalWrite(LED_redDir, HIGH);
      digitalWrite(LED_redEsq, HIGH);
      delay(150);
      digitalWrite(LED_redDir, LOW); 
      digitalWrite(LED_redEsq, LOW);
      delay(150);
    }

    while (digitalRead(BTN_f4) == LOW);
    delay(100);
  }
}