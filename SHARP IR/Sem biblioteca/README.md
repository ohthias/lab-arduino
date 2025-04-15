# Medição de Distância com Sensor IR Sharp (GP2Y0A41SK0F)

Este projeto utiliza um sensor infravermelho analógico Sharp GP2Y0A41SK0F para medir distâncias entre 4 cm e 30 cm, usando um Arduino. A distância é calculada a partir da leitura analógica e exibida no Monitor Serial.

O sensor Sharp GP2Y0A41SK0F gera uma tensão analógica proporcional à distância de um objeto. O Arduino lê essa tensão e a converte em centímetros usando uma fórmula baseada na curva de resposta do sensor.

## Componentes Necessários

- 1x Arduino Uno (ou similar)
- 1x Sensor Sharp IR GP2Y0A41SK0F
- Cabos jumper
- Protoboard (opcional)

## Como funciona:

- analogRead(sensor) lê um valor entre 0 e 1023.
- Multiplicando por 0.0048828125 (que equivale a 5V / 1024), converte-se o valor lido em volts.
- A fórmula distance = 13 * pow(volts, -1) é uma aproximação experimental para converter a tensão em centímetros.
- Só imprime a distância se for menor ou igual a 30 cm, respeitando o alcance do sensor.

## Diferenças

| Característica | Sharp IR | HC-SR04 |
| --- | --- | --- |
| Tipo de medição | Infravermelho (reflexão óptica) | Ultrassônico (eco de som) |
| Precisão em curta distância | Alta | Pode oscilar |
| Alcance típico | 10 cm a 80 cm (dependendo do modelo) | 2 cm a 400 cm |
| Saída | Analógica / PWM | Digital (trigger/echo) |
| Imune a ruído sonoro | Sim | Não |
| Dependente de luz ambiente | Um pouco | Não |