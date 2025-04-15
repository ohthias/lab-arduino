/*
   Teste de inclinação com o sensor MPU6050 para ajuste de velocidade dos motores.
   - Controlar a velocidade do robô de acordo com a inclinação detectada pelo sensor MPU6050.
   - Quanto maior a inclinação (angleX e angleY), menor será a velocidade dos motores.
   - Se o robô estiver plano (0° de inclinação), a velocidade será máxima.
   - Se a inclinação atingir 45° ou mais, a velocidade será reduzida ao mínimo para evitar desligamento total.

   Funcionamento:
   1. Lê os ângulos de inclinação `angleX` e `angleY` do MPU6050.
   2. Calcula a inclinação total usando a hipotenusa de X e Y.
   3. Ajusta a velocidade dos motores proporcionalmente, entre `MAX_SPEED` e `MIN_SPEED`.
   4. Aplica a velocidade usando PWM nos pinos dos motores.
*/

#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu6050;

// Pinos dos motores (PWM nos pinos habilitados)
#define MOTOR_LEFT_FORWARD 5
#define MOTOR_LEFT_BACKWARD 6
#define MOTOR_RIGHT_FORWARD 9
#define MOTOR_RIGHT_BACKWARD 10

// Velocidade base dos motores (0-255)
#define MAX_SPEED 255
#define MIN_SPEED 50  // Velocidade mínima para evitar desligamento total

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

    stopMotors();
}

void loop() {
    // Lê os ângulos do MPU6050
    float angleX = mpu6050.getAngleX();
    float angleY = mpu6050.getAngleY();
    float angleZ = mpu6050.getAngleZ(); // Apenas para referência

    // Calcula a inclinação total (hipotenusa de X e Y)
    float tilt = sqrt(angleX * angleX + angleY * angleY);

    // Calcula a velocidade proporcional à inclinação
    int speed = map(constrain(tilt, 0, 45), 0, 45, MAX_SPEED, MIN_SPEED);

    // Exibe os valores no Monitor Serial
    Serial.print("angleX : "); Serial.print(angleX);
    Serial.print("\tangleY : "); Serial.print(angleY);
    Serial.print("\tangleZ : "); Serial.print(angleZ);
    Serial.print("\tTilt: "); Serial.print(tilt);
    Serial.print("\tSpeed: "); Serial.println(speed);

    // Controla os motores ajustando a velocidade
    moveForward(speed);

    delay(50);
}

void moveForward(int velocidade) {
    analogWrite(MOTOR_LEFT_FORWARD, velocidade);
    analogWrite(MOTOR_LEFT_BACKWARD, 0);
    analogWrite(MOTOR_RIGHT_FORWARD, velocidade);
    analogWrite(MOTOR_RIGHT_BACKWARD, 0);
}

void stopMotors() {
    analogWrite(MOTOR_LEFT_FORWARD, 0);
    analogWrite(MOTOR_LEFT_BACKWARD, 0);
    analogWrite(MOTOR_RIGHT_FORWARD, 0);
    analogWrite(MOTOR_RIGHT_BACKWARD, 0);
}