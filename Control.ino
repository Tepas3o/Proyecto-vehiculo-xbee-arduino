#include <SoftwareSerial.h>
const int joystickXPin = A0;  // Pin analógico para el eje X del joystick
const int joystickYPin = A1;  // Pin analógico para el eje Y del joystick

void setup() {
  // Configurar la comunicación serial con el módulo XBee
  Serial.begin(9600);
}
void loop() {
  int joystickXValue = analogRead(joystickXPin);
  int joystickYValue = analogRead(joystickYPin);
  // Enviar comando para avanzar durante 2 segundos
   if (joystickYValue > 520 && joystickYValue <= 1023 ) {
    // Enviar comando para avanzar
    Serial.write('F');
  } else if (joystickYValue >=0 && joystickYValue < 480 ) {
    // Enviar comando para retroceder
    Serial.write('B');
  } else if (joystickXValue > 520 && joystickXValue <= 1023) {
    // Enviar comando para mover a la derecha
    Serial.write('R');
  } else if (joystickXValue >=0 && joystickXValue < 480) {
    // Enviar comando para mover a la izquierda
    Serial.write('L');
  }else if(joystickXValue > 480 && joystickXValue < 520 && joystickYValue > 480 && joystickYValue < 520) {
    // Enviar comando para detenerse
    Serial.write('S');
  }   

  // Esperar un breve período de tiempo
  delay(100);
}
