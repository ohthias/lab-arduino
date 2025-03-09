// Pinos do sensor de refletância
int sensor1 = A15;
int sensor2 = A14;
int sensor3 = A13;
int sensor4 = A12;
int sensor5 = A11;

// Variáveis de armazenamento dos valores coletados nos sensores de refletância
int sensorExtEsquerda,
  sensorEsquerda,
  sensorMeio,
  sensorDireita,
  sensorExtDireita = 0;

void setup() {
    Serial.begin(2400);

    // Saídas dos sensores de refletância
    pinMode(sensor1, INPUT);
    pinMode(sensor2, INPUT);
    pinMode(sensor3, INPUT);
    pinMode(sensor4, INPUT);
    pinMode(sensor5, INPUT);
}

void loop() {
    sensorExtDireita = analogRead(sensor1);
    sensorDireita = analogRead(sensor2);
    sensorMeio = analogRead(sensor3);
    sensorEsquerda = analogRead(sensor4);
    sensorExtEsquerda = analogRead(sensor5);

    // Imprimindo os valores dos sensores no monitor serial
    Serial.print("sensorExtDireita: ");
    Serial.print(sensorExtDireita);
    Serial.print("\t");

    Serial.print("sensorDireita: ");
    Serial.print(sensorDireita);
    Serial.print("\t");

    Serial.print("sensorMeio: ");
    Serial.print(sensorMeio);
    Serial.print("\t");

    Serial.print("sensorEsquerda: ");
    Serial.print(sensorEsquerda);
    Serial.print("\t");

    Serial.print("sensorExtEsquerda: ");
    Serial.println(sensorExtEsquerda);

    // Atraso de 500 ms para evitar excesso de prints
    delay(500);
}