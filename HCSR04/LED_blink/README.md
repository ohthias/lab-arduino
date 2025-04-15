# Medidor de Distância com LED e Sensor Ultrassônico (Usando afstandssensor)

Este projeto utiliza um sensor ultrassônico com a biblioteca afstandssensor para medir distâncias em centímetros. Um LED é controlado com base na proximidade de um objeto detectado:
- Se a distância for menor que 2 cm, a distância é impressa no Serial Monitor.
- Se a distância estiver entre 2 e 10 cm, o LED pisca.
- Se for maior que 10 cm, a distância é exibida no Serial Monitor.

## Componentes Utilizados

- 1x Arduino Uno (ou similar)
- 1x Sensor Ultrassônico HC-SR04
- 1x LED
- 1x Resistor 220Ω (para o LED)
- Cabos jumper
- Protoboard
  
## Instalação

1. Acesse o [repositório no GitHub](https://github.com/Teknologiskolen/HCSR04). https://github.com/Teknologiskolen/HCSR04
2. Baixe a biblioteca.
3. Adicione ao Arduino IDE via **Sketch > Incluir Biblioteca > Adicionar Biblioteca .ZIP**.