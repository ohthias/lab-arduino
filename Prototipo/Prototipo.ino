const int sensor = 8;
const int motors= 10;

#define ON HIGH
#define OFF LOW

int present_condition = 0;
int previous_condition = 0;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(motors, OUTPUT);
  Serial.begin(9600);
}

int leituraVibracao() {
  previous_condition = present_condition;
  present_condition = digitalRead(sensor);

  if (previous_condition != present_condition) {
    Serial.println("Estou ouvindo");
    digitalWrite(motors, ON);

  } else {
    Serial.println("Não Estou ouvindo");
    digitalWrite(motors, OFF);
  }
}

void loop() {
  leituraVibracao();
}
