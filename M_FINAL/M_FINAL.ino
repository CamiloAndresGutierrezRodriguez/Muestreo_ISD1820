const int audioPin = A0;         // Pin analógico
const int numMuestras = 200;     // Cantidad de muestras por bloque

int muestras[numMuestras];       // Arreglo para valores ADC
float voltajes[numMuestras];     // Arreglo para voltajes
unsigned long tiempos[numMuestras]; // Arreglo para tiempos

void setup() {
  Serial.begin(9600); // Comunicación serie
}

void loop() {
  Serial.println("--- Nuevo bloque ---");

  // Captura de muestras
  for (int i = 0; i < numMuestras; i++) {
    tiempos[i] = micros();                            // Tiempo en µs
    muestras[i] = analogRead(audioPin);               // Valor ADC (0–1023)
    voltajes[i] = (muestras[i] * 5.0) / 1023.0;       // Conversión a voltaje
    delayMicroseconds(125);                           // ~8 kHz de muestreo
  }

  // Impresión en formato: Tiempo - ADC - Voltaje
  for (int i = 0; i < numMuestras; i++) {
    Serial.print(tiempos[i]);
    Serial.print(" - ");
    Serial.print(muestras[i]);
    Serial.print(" - ");
    Serial.println(voltajes[i], 3);  // 3 decimales
  }

  Serial.println("--- Fin de bloque ---\n");

  delay(1000); // Pausa antes del siguiente bloque
}
