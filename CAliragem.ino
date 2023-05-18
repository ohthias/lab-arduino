/*
 * Esse programa faz a calibração automática do robo. Tanto para identificação de pret e verde.
 * Criado por: Matheus Gabriel
 * Data 16/05/23
*/

#define sen1 (A13)
#define sen2 (A12)
#define sen3 (A11)
#define sen4 (A10)
#define sen5 (A9)
#define sen6 (A8)
#define sen7 (A7)
#define sen8 (A14)

int minValue;
int maxValue = 0;
int pretoCorte = 0;

int BTN_f4 = 35;
int estadoBtn = 0;

int LED_green  = 9;
int LED_redEsq = 8;
int LED_redDir = 10;

void setup() {
  pinMode(LED_redEsq, OUTPUT);
  pinMode(LED_redDir, OUTPUT);
  pinMode(LED_green, OUTPUT);
  pinMode(BTN_f4, INPUT_PULLUP);
  pinMode(sen1, INPUT);
  pinMode(sen2, INPUT);
  pinMode(sen3, INPUT);
  pinMode(sen4, INPUT);
  pinMode(sen5, INPUT);
  pinMode(sen6, INPUT);
  pinMode(sen7, INPUT);
  pinMode(sen8, INPUT);
  Serial.begin(1200);
}

void loop() {
  minValue = 780;
  estadoBtn = digitalRead(BTN_f4);

  if (analogRead(sen1), analogRead(sen2), analogRead(sen3), analogRead(sen4), 
  analogRead(sen5), analogRead(sen6), analogRead(sen7), analogRead(sen8) > minValue) {
    digitalWrite(LED_redEsq, HIGH);
    digitalWrite(LED_redDir, HIGH);
    delay(100);
    digitalWrite(LED_redEsq, LOW);
    digitalWrite(LED_redDir, LOW);
    return;
  } if(analogRead(sen1), analogRead(sen2), analogRead(sen3), analogRead(sen4), 
  analogRead(sen5), analogRead(sen6), analogRead(sen7), analogRead(sen8) > minValue && estadoBtn == LOW){
    digitalWrite(LED_green, HIGH);;
    delay(100);
    digitalWrite(LED_green, LOW);
  }
  else {
    digitalWrite(LED_redEsq, LOW);
    digitalWrite(LED_redDir, LOW);
  }
  
}
