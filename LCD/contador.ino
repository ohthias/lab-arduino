#include <LiquidCrystal.h>

// Pinos do LCD conectados ao Arduino
const int rs = 3, en = 4, d4 = A2, d5 = A3, d6 = A4, d7 = A5;

// Inicializando o objeto LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  static int contador = 0;

  // Define o cursor na segunda linha
  lcd.setCursor(0, 1);
  
  // Apaga qualquer texto anterior para evitar sobreposição
  lcd.print("                "); // Espaços para limpar a linha
  
  lcd.setCursor(0, 1); // Move o cursor de volta para o início da linha
  lcd.print("Contagem: ");
  lcd.print(contador);
  
  contador++;
  delay(1000);
}