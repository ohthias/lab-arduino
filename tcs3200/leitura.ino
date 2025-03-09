// Pinos de conexao do modulo
#define pinS0E 8
#define pinS1E 9
#define pinS2E 10
#define pinS3E 11
#define pinOutE 11

unsigned int valorVermelhoE = 0;
unsigned int valorVerdeE = 0;
unsigned int valorAzulE = 0;
unsigned int valorBrancoE = 0;

void setup() {
    Serial.begin(9600);
    pinMode(pinS0E, OUTPUT);
    pinMode(pinS1E, OUTPUT);
    pinMode(pinS2E, OUTPUT);
    pinMode(pinS3E, OUTPUT);
    pinMode(pinOutE, INPUT);
}

void loop() {
    detectaCor();

    // Mostrar valores da esquerda no serial monitor
    Serial.print("Vermelho :");
    Serial.print(valorVermelhoE);
  
    Serial.print(" Verde : ");
    Serial.print(valorVerdeE);
  
    Serial.print(" Azul : ");
    Serial.print(valorAzulE);
  
    Serial.print(" Branco : ");
    Serial.print(valorBrancoE);
    Serial.println();
}

void detectaCor() {
    //Vermelho esquerda
    digitalWrite(pinS2E, LOW);
    digitalWrite(pinS3E, LOW);
    valorVermelhoE = pulseIn(pinOutE, digitalRead(pinOutE) == HIGH ? LOW : HIGH);
  
    //Sem filtro esquerda
    digitalWrite(pinS2E, HIGH);
    valorBrancoE = pulseIn(pinOutE, digitalRead(pinOutE) == HIGH ? LOW : HIGH);
  
    //Azul esquerda
    digitalWrite(pinS2E, LOW);
    digitalWrite(pinS3E, HIGH);
    valorAzulE = pulseIn(pinOutE, digitalRead(pinOutE) == HIGH ? LOW : HIGH);
  
    //Verde esquerda
    digitalWrite(pinS2E, HIGH);
    valorVerdeE = pulseIn(pinOutE, digitalRead(pinOutE) == HIGH ? LOW : HIGH);
}