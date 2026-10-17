#include <SPI.h>
#include <MFRC522.h>
#include <WiFis3.h>
#include "secrets.h"

#define SS_PIN 10
#define SS_RST 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

char ssid[] = secret_ssid;
char pass[] = secret_wifi_password;
int status = WL_IDLE_STATUS;
IPAddress serverAddress(192,168,1,101)
WiDiClient client;

void setup() {
  // put your setup code here, torun once:
 serial.begin(9600);
 SPI.begin();
 mfrc522.PCD_Init();


}

void loop() {
  // put your main code here, to run repeatedly:
  
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size;i++){
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "))
    content.concat(String(mfrc522.uid.uidByte[i],HEX))
  }
  LogVisit(content);
}

void LogVisit(String uid ) {
  if(client.connect("192.168.1.101", 3000)){
      Serial.println("connected to server");
      client println("GET /log?uid=" + uid +" HTTP/1.1");
      client.println("Host: 192.168.1.101");
      client.println("Connection: close")
      client.println();
      client.stop();
  }else{
    Serial.println("not connected");
  }
}


