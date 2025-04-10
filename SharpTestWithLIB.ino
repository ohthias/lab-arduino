//Link da biblioteca usada: https://github.com/qub1750ul/Arduino_SharpIR

#include <SharpIR.h>

SharpIR sensor( SharpIR::GP2Y0A41SK0F, A0 );

void setup() {
  Serial.begin(9600);
}

void loop() {
  int distanciaAtual = sensor.getDistance();

  Serial.println(distanciaAtual);
}
