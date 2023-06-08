int PINO_LED_R = 7;  // Vermelho
int PINO_LED_G = 5;  // Verde
int PINO_LED_B = 6; // Azul

void setup() {
  // Configurando os pinos como saida
  pinMode(PINO_LED_R, OUTPUT); // LED vermelho
  pinMode(PINO_LED_G, OUTPUT); // LED verde
  pinMode(PINO_LED_B, OUTPUT); // LED azul
}

void loop() {
  // Ligando o LED vermelho e desligando o LED azul e verde
  digitalWrite(PINO_LED_R, HIGH); // Liga LED vermelho
  digitalWrite(PINO_LED_G, LOW);  // Desliga LED verde
  digitalWrite(PINO_LED_B, LOW);  // Desliga LED azul
  delay(2000);                    // Deixando dois segundos aceso LED vermelho
  digitalWrite(PINO_LED_R, LOW);  // Desliga LED vermelho
  delay(2000);                    // Espera dois segundos para ligar o proximo LED

  // Ligando LED verde e desligando LED vermelho e verde
  digitalWrite(PINO_LED_R, LOW);  // Desliga LED vermelho
  digitalWrite(PINO_LED_G, HIGH); // Liga LED verde
  digitalWrite(PINO_LED_B, LOW);  // Desliga LED azul
  delay(2000);                    // Deixando dois segundos aceso LED verde
  digitalWrite(PINO_LED_G, LOW);  // Desliga LED verde
  delay(2000);                    // Espera dois segundos para ligar proximo LED

  // Ligando LED azul e desligando LED vermelho e verde
  digitalWrite(PINO_LED_R, LOW);  // Desliga LED vermelho
  digitalWrite(PINO_LED_G, LOW);  // Desliga LED verde
  digitalWrite(PINO_LED_B, HIGH); // Liga LED azul
  delay(2000);                    // Deixando 2 segundos para ligar proximo LED
  digitalWrite(PINO_LED_B, LOW);  // Desliga LED azul
  delay(2000);                    // Espera 2 segundos para voltar ao  LED vermelho

  // Ligando LED vermelho e azul para criar roxo
  digitalWrite(PINO_LED_R, HIGH); // Liga LED vermelho
  digitalWrite(PINO_LED_G, LOW);  // Desliga LED verde
  digitalWrite(PINO_LED_B, HIGH); // Liga LED azul
  delay(2000);                    // Deixando 2 segundos para ligar proximo LED
  digitalWrite(PINO_LED_R, LOW);  // Desliga LED vermelho
  digitalWrite(PINO_LED_B, LOW);  // Desliga LED azul
  delay(2000);                    // Espera dois segundos para voltar ao vermelho
}
