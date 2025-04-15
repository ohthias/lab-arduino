#include <LiquidCrystal.h>

const int rs = 3, en = 4, d4 = A2, d5 = A3, d6 = A4, d7 = A5;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  static int contador = 0;

  lcd.setCursor(0, 1);
  
  lcd.print("                ");
  
  lcd.setCursor(0, 1);
  lcd.print("Contagem: ");
  lcd.print(contador);
  
  contador++;
  delay(1000);
}