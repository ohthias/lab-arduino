#include <Wire.h>
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

void setup() {
  Serial.begin(9600);

  if (tcs.begin()) {
    Serial.println("Sensor encontrado");
  } 
  else{
    Serial.println("Sensor nÃ£o encontrado, cheque suas conecÃ§Ãµes.");
    while (1);
  }
}

void loop() {
  uint16_t r, g, b, c;

  tcs.getRawData(&r, &g, &b, &c);

  Serial.print("Vermelho : "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("Verde    : "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("Azul     : "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("Claridade: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");
}