#include <SoftwareSerial.h>
SoftwareSerial BTSerial(11, 10); // RX, TX

void setup() {
  BTSerial.begin(57600);
  Serial.begin(9600);
}

void loop() {
  if (BTSerial.available()) {
  byte data = BTSerial.read();
  Serial.print("Gelen Veri (HEX): ");
  Serial.println(data, HEX);
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }


  if (BTSerial.available()) {
    byte incomingByte = BTSerial.read();
    
    if (incomingByte == 0xAA) { // Paket başlığı
      byte secondByte = BTSerial.read();
      if (secondByte == 0xAA) {
        byte payloadLength = BTSerial.read(); // Paket uzunluğu
        byte payload[payloadLength];
        byte checksum = 0;

        for (int i = 0; i < payloadLength; i++) {
          payload[i] = BTSerial.read();
          checksum += payload[i];
        }

        checksum = ~checksum;
        byte receivedChecksum = BTSerial.read();

        if (checksum == receivedChecksum) {
          Serial.println("Veri Alındı:");
          for (int i = 0; i < payloadLength; i++) {
            Serial.print(payload[i], HEX);
            Serial.print(" ");
          }
          Serial.println();
        }
      }
    }
  }
}
