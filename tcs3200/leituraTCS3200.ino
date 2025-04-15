// Pinos de conexao do modulo
#define pinS0 2
#define pinS1 3
#define pinS2 4
#define pinS3 5
#define pinOut 6

unsigned int valorVermelho = 0;
unsigned int valorVerde = 0;
unsigned int valorAzul = 0;
unsigned int valorBranco = 0;

void setup() {
    Serial.begin(9600);
    pinMode(pinS0, OUTPUT);
    pinMode(pinS1, OUTPUT);
    pinMode(pinS2, OUTPUT);
    pinMode(pinS3, OUTPUT);
    pinMode(pinOut, INPUT);
}

void loop() {
    detectaCor();

    // Mostrar valores da esquerda no serial monitor
    Serial.print("Vermelho :");
    Serial.print(valorVermelho);
  
    Serial.print(" Verde : ");
    Serial.print(valorVerde);
  
    Serial.print(" Azul : ");
    Serial.print(valorAzul);
  
    Serial.print(" Branco : ");
    Serial.print(valorBranco);
    Serial.println();
}

void detectaCor() {
    //Vermelho esquerda
    digitalWrite(pinS2, LOW);
    digitalWrite(pinS3, LOW);
    valorVermelho = pulseIn(pinOut, digitalRead(pinOut) == HIGH ? LOW : HIGH);
  
    //Sem filtro esquerda
    digitalWrite(pinS2, HIGH);
    valorBranco = pulseIn(pinOut, digitalRead(pinOut) == HIGH ? LOW : HIGH);
  
    //Azul esquerda
    digitalWrite(pinS2, LOW);
    digitalWrite(pinS3, HIGH);
    valorAzul = pulseIn(pinOut, digitalRead(pinOut) == HIGH ? LOW : HIGH);
  
    //Verde esquerda
    digitalWrite(pinS2, HIGH);
    valorVerde = pulseIn(pinOut, digitalRead(pinOut) == HIGH ? LOW : HIGH);
}