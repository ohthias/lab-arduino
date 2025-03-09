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

  O código também inclui verificações para garantir que o sistema só responda a um novo estado do botão quando ele for solto, utilizando uma pequena pausa (`delay(100)`).

  A comunicação serial é usada para imprimir as distâncias medidas para depuração.
  
  Esse código é útil para sistemas de robôs simples com sensores ultrassônicos para navegação ou detecção de obstáculos.
*/

#include <HCSR04.h>

// Definição dos sensores
UltraSonicDistanceSensor sensorFrente(45, 44);
UltraSonicDistanceSensor sensorEsq(49, 48);
UltraSonicDistanceSensor sensorDir(46, 47);

// Definição das variáveis de distâncias
int distancia, distanciaLatEsq, distanciaLatDir;
int alvo = 10;

// Definição dos LEDs
int LED_green = 9;
int LED_redEsq = 8;
int LED_redDir = 10;

// Definição do botão
int BTN_f4 = 35;
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
  
  // Quando o botão for pressionado
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

  // Quando o botão não estiver pressionado
  if (estadoBtn == LOW) {
    // Se o sensor frontal medir uma distância menor que o valor alvo
    if (distancia <= alvo && distancia > 5) {
      Serial.println(distancia); // Exibe a distância medida
      digitalWrite(LED_green, HIGH);

      // Verifica se o sensor esquerdo está dentro do alvo
      if (distanciaLatEsq <= alvo && distanciaLatEsq > 4) {
        Serial.print(distanciaLatEsq);
        digitalWrite(LED_redEsq, HIGH);
        delay(100);
      } 
      // Verifica se o sensor direito está dentro do alvo
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