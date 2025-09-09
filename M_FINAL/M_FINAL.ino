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

    // Ajuste de resolución: redondear a pasos de 0.02 V
    voltaje = round(voltaje / 0.03) * 0.03;

    Serial.println(voltaje, 2);          // Imprime con 2 decimales
    delayMicroseconds(125);              // ~8 kHz de muestreo
  }
  // --- Fin de bloque ---

  delay(1000); // Pausa 1 segundo antes del siguiente bloque
}

// const int audioPin = A0;         // Pin analógico
// const int numMuestras = 200;     // Cantidad de muestras por bloque

// int muestras[numMuestras];       // Arreglo para valores ADC
// float voltajes[numMuestras];     // Arreglo para voltajes
// unsigned long tiempos[numMuestras]; // Arreglo para tiempos

// void setup() {
//   Serial.begin(9600); // Comunicación serie
// }

// void loop() {
//   Serial.println("--- Nuevo bloque ---");

//   // Captura de muestras
//   for (int i = 0; i < numMuestras; i++) {
//     tiempos[i] = micros();                            // Tiempo en µs
//     muestras[i] = analogRead(audioPin);               // Valor ADC (0–1023)
//     voltajes[i] = (muestras[i] * 5.0) / 1023.0;       // Conversión a voltaje
//     delayMicroseconds(125);                           // ~8 kHz de muestreo
//   }

//   // Impresión en formato: Tiempo - ADC - Voltaje
//   for (int i = 0; i < numMuestras; i++) {
//     Serial.print(tiempos[i]);
//     Serial.print(" - ");
//     Serial.print(muestras[i]);
//     Serial.print(" - ");
//     Serial.println(voltajes[i], 3);  // 3 decimales
//   }

//   Serial.println("--- Fin de bloque ---\n");

//   delay(1000); // Pausa antes del siguiente bloque
// }
