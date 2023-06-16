  #include <SoftwareSerial.h>

// Definición de los pines del controlador L298N
const int motorA_1 = 2;   // Pin IN1 del Motor A
const int motorA_2 = 3;   // Pin IN2 del Motor A
const int motorB_1 = 4;   // Pin IN3 del Motor B
const int motorB_2 = 5;   // Pin IN4 del Motor B
const int enableA = 9;    // Pin Enable del Motor A
const int enableB = 10;   // Pin Enable del Motor B


// Definición de los comandos de control

void setup() {
  // Configurar los pines del controlador L298N como salidas
  pinMode(motorA_1, OUTPUT);
  pinMode(motorA_2, OUTPUT);
  pinMode(motorB_1, OUTPUT);
  pinMode(motorB_2, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
 

  // Configurar la comunicación serial con el módulo XBee
  Serial.begin(9600);
}

void loop() { 
    if (Serial.available()) {
     char cmd = Serial.read();   //Definir una variable cmd de lectura de la comuniación serial entre los módulos XBee
    Serial.print("Comando recibido: ");
    
    Serial.println(cmd);
    

    // Realizar el movimiento correspondiente de los motores según el comando recibido
    if ( cmd == 'F') {
      // Mover hacia adelante
      digitalWrite(motorA_1, HIGH);
      digitalWrite(motorA_2, LOW);
      digitalWrite(motorB_1, HIGH);
      digitalWrite(motorB_2, LOW);
      digitalWrite(enableA,HIGH);
      digitalWrite(enableB,HIGH);
      delay(50);
    } else if (cmd == 'B') {
      // Mover hacia atrás
      digitalWrite(motorA_1, LOW);
      digitalWrite(motorA_2, HIGH);
      digitalWrite(motorB_1, LOW);
      digitalWrite(motorB_2, HIGH);
      digitalWrite(enableA,HIGH);
      digitalWrite(enableB,HIGH);
      delay(50);
      
    } else if (cmd == 'R') {
      // Mover hacia la derecha
      digitalWrite(motorA_1, LOW);
      digitalWrite(motorA_2, HIGH);
      //digitalWrite(motorB_1, HIGH);
      //digitalWrite(motorB_2, HIGH);
      digitalWrite(enableA,HIGH);
      //digitalWrite(enableB,HIGH);
      delay(50);
  } else if (cmd == 'L') {
      // Mover hacia la izquierda
      //digitalWrite(motorA_1, HIGH);
      //digitalWrite(motorA_2, LOW);
      digitalWrite(motorB_1, LOW);
      digitalWrite(motorB_2, HIGH);
      //digitalWrite(enableA,HIGH);
      digitalWrite(enableB,HIGH);
      delay(50);
  } else if (cmd == 'S') {
      // Detener los motores
      digitalWrite(motorA_1, LOW);
      digitalWrite(motorA_2, LOW);
      digitalWrite(motorB_1, LOW);
      digitalWrite(motorB_2, LOW);
      digitalWrite(enableA,HIGH);
      digitalWrite(enableB,HIGH);
      delay(50);
  } 
    } } 
    
