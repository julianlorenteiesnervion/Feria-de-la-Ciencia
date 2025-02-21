#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

// Definimos los pines a los que está conectado el sensor
const int trigPin = 9;  // Pin Trig conectado al pin digital 9
const int echoPin = 10; // Pin Echo conectado al pin digital 10

// Definimos la distancia límite en centímetros
const int distanciaLimite = 15;

void setup() {
  // Inicializamos la comunicación serial
  Serial.begin(9600);

  Braccio.begin(5);
  
  // Configuramos los pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Medimos la distancia
  long duracion, distancia;
  
  // Enviamos un pulso corto al pin Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Medimos el tiempo que tarda en llegar el eco
  duracion = pulseIn(echoPin, HIGH);
  
  // Convertimos el tiempo en distancia (en cm)
  distancia = duracion * 0.034 / 2;
  
  // Mostramos la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  // Verificamos si la distancia es menor o igual a 15 cm
  if (distancia <= distanciaLimite) {
    // Ejecutamos el código que deseas cuando la distancia es menor o igual a 15 cm
    ejecutarCodigo();
  }
  
  // Pequeña pausa antes de la siguiente medición
  delay(100);
}

// Función que contiene el código a ejecutar cuando la distancia es menor o igual a 15 cm
void ejecutarCodigo() {
  // Aquí colocas el código que deseas ejecutar
  Serial.println("¡Distancia menor o igual a 15 cm!");
  // Por ejemplo, puedes encender un LED, activar un motor, etc.
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