#include <ELECHOUSE_CC1101_SRC_DRV.h>

#include <SimpleRelay.h>

constexpr static byte RELAY_PIN = 6;
SimpleRelay relay = SimpleRelay(RELAY_PIN);



void setup() {
  Serial.begin(9600);
  if (ELECHOUSE_cc1101.getCC1101()) {
    Serial.println("CC1101 is connected");
    ELECHOUSE_cc1101.Init();              // Initialize CC1101
    ELECHOUSE_cc1101.setMHZ(433.0);       // Set frequency to 433 MHz
  } else {
    Serial.println("CC1101 not connected");
  }
  relay.off();
}

void loop() {
//      // Example: Transmit data     
//      char txBuffer[] = "of";
//      ELECHOUSE_cc1101.SendData(txBuffer, sizeof(txBuffer));
//      Serial.println("Data sent!");
//  
//      delay(1000);  // Wait for a second before sending again

  // Example: Receive data
  if (ELECHOUSE_cc1101.CheckReceiveFlag()) {
    char rxBuffer[64] = {0};
    int len = ELECHOUSE_cc1101.ReceiveData(rxBuffer);
    if (len > 0) {
      Serial.print("Received data: ");
      Serial.println(rxBuffer);
          }     
  
   if (rxBuffer == "on") {
        relay.on();
        delay(100);
      }
      if (rxBuffer == "of") {
        relay.on();
        delay(100);
      }
  }

  
}
