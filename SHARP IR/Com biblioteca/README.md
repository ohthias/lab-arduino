# SHARP IR usando biblioteca

Por ser amplamente usado, o Sharp IR possui várias bibliotecas disponíveis, o que facilita a implementação no Arduino sem a necessidade de cálculos complexos.

A recomendada aqui é a biblioteca **SharpIR.h**, criada por [qub1750ul (Magical Quantum Compute)](https://github.com/qub1750ul/Arduino_SharpIR). Ela encapsula os cálculos e fornece um método direto para ler a distância em **centímetros**.

## Instalação

1. Acesse o [repositório no GitHub](https://github.com/qub1750ul/Arduino_SharpIR). https://github.com/qub1750ul/Arduino_SharpIR
2. Baixe a biblioteca.
3. Adicione ao Arduino IDE via **Sketch > Incluir Biblioteca > Adicionar Biblioteca .ZIP**.

## Declaração e método

```arduino
SharpIR sensor( SharpIR::model, port );

int distanciaAtual = sensor.getDistance();
```