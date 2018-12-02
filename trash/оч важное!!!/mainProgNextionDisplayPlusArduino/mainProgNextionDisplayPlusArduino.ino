#include <SoftwareSerial.h>

const int btn = 5;
int btnState = 0;
SoftwareSerial mySerial(3, 2); 

void setup() {
  pinMode(btn, INPUT);
  Serial.begin(9600); 
  while (!Serial) { ; }
  Serial.println("Serial On"); 
  mySerial.begin(9600); 
}

void loop() {
  btnState = digitalRead(btn);
  String sendThis = "pic "; 

  if (btnState == HIGH) {
    sendThis.concat("10,35,2"); 
  } else {
//    sendThis.concat("6,38,1"); 
      sendThis.concat("6,40,1"); 
  }

  delay(300); 
  writeString(sendThis); 
}

void writeString(String stringData) { 
  for (int i = 0; i < stringData.length(); i++){
    mySerial.write(stringData[i]);   
  }
  mySerial.write(0xff); 
  mySerial.write(0xff); 
  mySerial.write(0xff);
}
