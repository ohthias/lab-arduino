# Contador com Display LCD 16x2 (Arduino)
Este projeto exibe uma contagem crescente em um display LCD 16x2 usando a biblioteca LiquidCrystal com interface de 4 bits. A contagem é atualizada a cada segundo e mostrada na segunda linha do display.

Utilizando um Arduino e um display LCD 16x2, o código imprime continuamente um contador na tela. A biblioteca LiquidCrystal é usada para comunicação com o LCD por meio de 6 pinos digitais/analógicos.

## Componentes Necessários

- 1x Arduino Uno (ou similar)
- 1x Display LCD 16x2 (com ou sem módulo I2C)
- Cabos jumper
- Potenciômetro (opcional, para contraste)
- Protoboard

```
Se estiver usando um módulo I2C para o LCD, este código não será compatível — será necessário usar a biblioteca LiquidCrystal_I2C.
```