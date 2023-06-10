#include <HardwareSerial.h>

#define RXD0 3  // Pin GPIO para RXD0
#define TXD0 1  // Pin GPIO para TXD0
#define RXD2 16 // Pin GPIO para RXD2
#define TXD2 17 // Pin GPIO para TXD2

HardwareSerial Serial2(2); // Creamos una instancia de HardwareSerial para UART2

void setup() {
  Serial.begin(115200);     // Iniciamos la comunicación serial para el monitor serial
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2); // Iniciamos la comunicación serial para UART2

  pinMode(RXD0, INPUT);     // Configuramos RXD0 como entrada
  pinMode(TXD0, OUTPUT);    // Configuramos TXD0 como salida
}

void loop() {
  // Leer datos de RXD0 y reenviar a TXD2
  if (Serial.available()) {
    char data = Serial.read();
    Serial2.write(data);
  }

  // Leer datos de RXD2 y reenviar a TXD0
  if (Serial2.available()) {
    char data = Serial2.read();
    Serial.write(data);
  }
}
