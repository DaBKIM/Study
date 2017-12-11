#include<SoftwareSerial.h>

// Wifi Serial communication
SoftwareSerial mySerial(3,2); 

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200); 
}

void loop() {
  
  if(mySerial.available()){
    // Print Wifi content to a Serial momitor
    Serial.write(mySerial.read());
  }
  if(Serial.available()){
    // Write Serial monitor content in Wifi server
    mySerial.write(Serial.read());
  }

}
