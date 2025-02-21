#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
    Serial.begin(9600);  // Inicia la comunicación serie
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    long duration;
    float distance;

    // Enviar un pulso al sensor
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Medir el tiempo del eco
    duration = pulseIn(ECHO_PIN, HIGH);

    // Convertir tiempo en distancia (cm)
    distance = duration * 0.0343 / 2;

    // Imprimir distancia por pantalla
    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(1000);  // Esperar medio segundo antes de la siguiente medición
}
