/*
   Teste de rotação até um ângulo alvo com o sensor MPU6050
   - Fazer o robô girar no seu próprio eixo até alcançar um ângulo de rotação alvo em torno do eixo Z.
   - A rotação é controlada pelos motores, e o processo para quando o ângulo atual atinge o valor desejado.

   Funcionamento:
   1. Lê o ângulo de rotação ao redor do eixo Z (`angleZ`) do MPU6050.
   2. Calcula a diferença entre o ângulo atual e o ângulo alvo.
   3. Controla os motores para girar o robô até o ângulo desejado.
   4. O robô gira para a esquerda ou direita dependendo do sinal da diferença entre o ângulo atual e o alvo.
*/

#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu6050;

// Pinos dos motores
#define MOTOR_LEFT_FORWARD 5
#define MOTOR_LEFT_BACKWARD 6
#define MOTOR_RIGHT_FORWARD 9
#define MOTOR_RIGHT_BACKWARD 10

int velocidade = 80;

// Ângulo alvo para rotação
float anguloAlvo = "ânguloAlvo";
bool meta = false;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    mpu6050.initialize();

    if (!mpu6050.testConnection()) {
        Serial.println("Erro ao conectar ao MPU6050!");
        while (1);
    }

    Serial.println("MPU6050 Conectado!");

    // Configura os pinos dos motores como saída
    pinMode(MOTOR_LEFT_FORWARD, OUTPUT);
    pinMode(MOTOR_LEFT_BACKWARD, OUTPUT);
    pinMode(MOTOR_RIGHT_FORWARD, OUTPUT);
    pinMode(MOTOR_RIGHT_BACKWARD, OUTPUT);

    // Zerar os motores no início
    stopMotors();
}

void loop() {
    // Lê os ângulos do MPU6050
    float angleX = mpu6050.getAngleX();
    float angleY = mpu6050.getAngleY();
    float angleZ = mpu6050.getAngleZ(); // Rotação no próprio eixo

    // Exibe os valores no Monitor Serial
    Serial.print("angleX : "); Serial.print(angleX);
    Serial.print("\tangleY : "); Serial.print(angleY);
    Serial.print("\tangleZ : "); Serial.println(angleZ);

    // Verifica se o robô já atingiu o ângulo alvo
    if (!meta) {
        if (abs(angleZ) < anguloAlvo) {
            rotateRobot();
        } else {
            stopMotors();
            meta = true;
            Serial.println("Alvo atingido!");
        }
    }

    delay(50);
}

// Função para girar no próprio eixo
void rotateRobot() {
    analogRead(MOTOR_LEFT_FORWARD, velocidade);
    analogRead(MOTOR_LEFT_BACKWARD, 0);
    analogRead(MOTOR_RIGHT_FORWARD, 0);
    analogRead(MOTOR_RIGHT_BACKWARD, velocidade);
}

// Função para parar os motores
void stopMotors() {
    analogRead(MOTOR_LEFT_FORWARD, 0);
    analogRead(MOTOR_LEFT_BACKWARD, 0);
    analogRead(MOTOR_RIGHT_FORWARD, 0);
    analogRead(MOTOR_RIGHT_BACKWARD, 0);
}
