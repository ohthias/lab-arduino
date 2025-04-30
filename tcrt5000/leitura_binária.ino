#define sen1 (A13)
#define sen2 (A12)
#define sen3 (A11)
#define sen4 (A10)
#define sen5 (A9)
#define sen6 (A8)
#define sen7 (A7)
#define sen8 (A14)
/* 
    Função para leitura dos sensores de refletância, 
    utilizando tabela da verdade (binário)
*/

int leituraSensor(){

    int numSen = 8;
    unsigned int leitura[8];

    leitura[0] = analogRead(sen1);
    leitura[1] = analogRead(sen2);
    leitura[2] = analogRead(sen3);
    leitura[3] = analogRead(sen4);
    leitura[4] = analogRead(sen5);
    leitura[5] = analogRead(sen6);
    leitura[6] = analogRead(sen7);
    leitura[7] = analogRead(sen8);

    Serial.println();

    int ligado = 0;
    int multiplicador = 1;
    int caso = 0;

    for (int i = 0; i < numSen; i++) {
        if (leitura[i] > preto && leitura[i] < pretoCorte) {
            ligado = 1;
        } else {
            if (leitura[i] > pretoCorte) {
                caso = 0;
                break;
            } else {
                ligado = 0;
            }
        }

        caso = caso + (ligado * multiplicador);
        multiplicador = multiplicador * 10;
    }
    return caso;
}