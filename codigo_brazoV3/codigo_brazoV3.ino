#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

void setup() {  
  Braccio.begin(5);
  Serial.begin(9600); // Inicia la comunicación serie
  Serial.println("Escribe 'E' para ejecutar el código.");
}

void loop() {
  if (Serial.available() > 0) {  // Si hay datos en el puerto serie
    char input = Serial.read(); // Lee el primer carácter recibido
    if (input == 'E') {  // Si el carácter es 'E', ejecuta el código original

      // Posición para coger la carga (pinzas abiertas)
      Braccio.ServoMovement(50, // Delay entre movimientos
                            90, // 0 - 180
                            45, // 15 - 165
                            175, // 0 - 180
                            180, // 0 - 180
                            90, // 0 - 180
                            0 // 10 - 73
                           );

      delay(1000);

      // Agarra la carga
      Braccio.ServoMovement(50, // Delay entre movimientos
                            90, // 0 - 180
                            45, // 15 - 165
                            175, // 0 - 180
                            180, // 0 - 180
                            90, // 0 - 180
                            73 // 10 - 73
                           );

      delay(1000);

      // Levanta la carga
      Braccio.ServoMovement(50, // Delay entre movimientos
                            90, // 0 - 180
                            45, // 15 - 165
                            90, // 0 - 180
                            180, // 0 - 180
                            90, // 0 - 180
                            73 // 10 - 73
                           );

      // Rota hasta otra posición para dejar la carga (dejando la carga levantada)
      Braccio.ServoMovement(50, // Delay entre movimientos
                            0, // 0 - 180
                            45, // 15 - 165
                            90, // 0 - 180
                            180, // 0 - 180
                            90, // 0 - 180
                            73 // 10 - 73
                           );

      // Baja la carga
      Braccio.ServoMovement(50, // Delay entre movimientos
                            0, // 0 - 180
                            45, // 15 - 165
                            130, // 0 - 180
                            180, // 0 - 180
                            90, // 0 - 180
                            73 // 10 - 73
                           );

      // Abre las pinzas para soltar la carga
      Braccio.ServoMovement(50, // Delay entre movimientos
                            0, // 0 - 180
                            45, // 15 - 165
                            130, // 0 - 180
                            180, // 0 - 180
                            90, // 0 - 180
                            0 // 10 - 73
                           );

      // Levanta el brazo con las pinzas abiertas
      Braccio.ServoMovement(50, // Delay entre movimientos
                            0, // 0 - 180
                            45, // 15 - 165
                            90, // 0 - 180
                            180, // 0 - 180
                            90, // 0 - 180
                            0 // 10 - 73
                           );

      // Rota el brazo con las pinzas abiertas
      Braccio.ServoMovement(50, // Delay entre movimientos
                            90, // 0 - 180
                            45, // 15 - 165
                            90, // 0 - 180
                            180, // 0 - 180
                            90, // 0 - 180
                            0 // 10 - 73
                           );
    }
  }
}
