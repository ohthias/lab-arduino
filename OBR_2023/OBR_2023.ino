#include <Encoder.h>
#include <HCSR04.h>
boolean rampa;
int leituraSensor;

// Definição do sensores de refletância
#define sen1 (A13)
#define sen2 (A12)
#define sen3 (A11)
#define sen4 (A10)
#define sen5 (A9)
#define sen6 (A8)
#define sen7 (A7)
#define sen8 (A14)

// Definição dos sensores de cor

#define ldr1 (A0)
#define ldr2 (A1)

// Definição dos sensores ultrasonicos

UltraSonicDistanceSensor sensorFrente (45, 44);
UltraSonicDistanceSensor sensorEsq (49, 48);
UltraSonicDistanceSensor sensorDir (46, 47);
int distace, distaceLatEsq, distaceLatDir;
int alvo = 10;

// Definição dos LEDS

int LED_green  = 9;
int LED_redEsq = 8;
int LED_redDir = 10;

// Definição dos Botões

int BTN_f4 = 35;
int BTN_f3 = 0;
int BTN_f2 = 0;
int BTN_f1 = 0;

// Globais e regulação

int preto; // Valor de refletancia do preto
int pretoCorte = 990; // Valor de descarte de preto, usado para acertar os redutores de velocidade
int l_linha = 200; // largura da linha

int ajuste = 200; // Regulação da distância do sensor de cor
int verdeEsq = 400; 
int verdeDir = 400;
int corteVerde1 = 375; // Valor de corte
int corteVerde2 = 375;

//Velocidade dos Motores
int F1 = 200;          //forca a ser aplicada no motor 1 (direita)
int F2 = 200;           //forca a ser aplicada no motor 2 (esquerda)
int FG = 150;
int FC = 100;
int tempo_atual = 0;
int tempo = 0;
float obst = 0;
float distancia_parada = 11;

//Valores dos obstáculos
int curvanoventa       = 1650;    //número de pulsos do encoder para uma curva de noventa graus
int curvanoventaesqu   = 1450;
int curva_direita  = 2000;    //período que o robô leva para fazer uma curva de 90º direita
int curva_esquerda = 1700;    //período que o robô leva para fazer uma curva de 90º esquerda
int comp_obs       = 5000;    //comprimento do obstáculo
int larg_obs       = 4750;    //largura do obstáculo


//REGULAGEM DO ROBÔ ACABA AQUI

void setup() {
  Serial.begin(15900);
  
  pinMode(sen1, INPUT);
  pinMode(sen2, INPUT);
  pinMode(sen3, INPUT);
  pinMode(sen4, INPUT);
  pinMode(sen5, INPUT);
  pinMode(sen6, INPUT);
  pinMode(sen7, INPUT);
  pinMode(sen8, INPUT);

  pinMode(LED_green, OUTPUT);
  pinMode(LED_redEsq, OUTPUT);
  pinMode(LED_redDir, OUTPUT);

  pinMode(BTN_f1, INPUT_PULLUP);
  pinMode(BTN_f2, INPUT_PULLUP);
  pinMode(BTN_f3, INPUT_PULLUP);
  pinMode(BTN_f4, INPUT_PULLUP);
}

void loop() {
  // Escrever código
  while (rampa == false) {



    int leitura_verdade = leituraSensor();          // leitura dos sensores de refletância, classificação de ligado/desligado pela tabela verdade
    Serial.println(leitura_verdade);                 // imprime as leituras em serial
    segue_linha(leitura_verdade);                    // sobe condição da leitura atual no segue linha



    tempo_atual = millis();


    tempo = tempo_atual - ultima_medida;
    //Serial.println(tempo);
    if (tempo > 50) {
      ultima_medida = tempo_atual;
      tempo = 0;
      obst = distancia_frente();
      dist_dir = distancia_lateral();
      dist_esq = esq_distancia_lateral();
      Serial.println("entrei");
        if (obst < distancia_parada && obst!=0 ) {
          Serial.println("DESVIA");
          desvia();
        }
        
        

        if (dist_dir < 10 || dist_esq < 10 && dist_dir != 0 && dist_esq != 0){
          contador = contador + 1;
          Serial.println(contador);
          Serial.println(dist_dir);
          Serial.println(dist_esq);
          }
          else{
            contador = 0;
            }

            if (contador > 10){
              rampa = true;
              }


    }

    Serial.println(leitura_verdade);
    Serial.println(obst);
}

  while (rampa == true){
    
    int leitura_verdade = leitura_sensor();          // leitura dos sensores de refletância, classificação de ligado/desligado pela tabela verdade
    Serial.println(contador);
    Serial.println("rampa");                 // imprime as leituras em serial
    segue_rampa(leitura_verdade);                    // sobe condição da leitura atual no segue linha
    tempo_atual = millis();
    tempo = tempo_atual - ultima_medida;
    if (tempo > 100) {
      ultima_medida = tempo_atual;
      tempo = 0;
      dist_dir = distancia_lateral();
      dist_esq = esq_distancia_lateral();
      Serial.println(dist_esq);  
        if (dist_esq > 10 ){
          contador = contador + 1;
          
          }
          else{
            contador = 0;
            }

         if (contador > 10){
           rampa = false;
              }
    }
 }

while (rampa == false){
  
  delay(10000);
  */resgate();
}
