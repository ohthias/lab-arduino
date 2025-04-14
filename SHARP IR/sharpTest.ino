#define sensor A0 // Sharp IR GP2Y0A41SK0F (4-30cm, analog)

void setup() {
  Serial.begin(9600);
}

void loop() {
  // 5v
  float volts = analogRead(sensor)*0.0048828125; 
  int distance = 13*pow(volts, -1);
  
  if (distance <= 30){
    Serial.println(distance);  
  }
}
