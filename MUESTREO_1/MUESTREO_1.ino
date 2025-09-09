const int audioPin = A0;     // Pin analógico
const int numMuestras = 100; // Cantidad de muestras por bloque
int valor = 0;
float voltaje = 0;

void setup() {
  Serial.begin(9600); // Comunicación serie
}

void loop() {
  // --- Nuevo bloque ---
  for (int i = 0; i < numMuestras; i++) {
    valor = analogRead(audioPin);        // Lectura ADC (0–1023)
    voltaje = (valor * 5.0) / 1023.0;    // Conversión a voltaje (0–5 V)

    // Ajuste de resolución: redondear a pasos de 0.03 V
    voltaje = round(voltaje / 0.03) * 0.03;

    Serial.println(voltaje, 2);          // Imprime con 2 decimales
    delayMicroseconds(125);              // ~8 kHz de muestreo
  }
  // --- Fin de bloque ---

  delay(1000); // Pausa 1 segundo antes del siguiente bloque
}
