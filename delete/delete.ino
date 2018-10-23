//const int DistanceSensor = 53;
//int buttonStateDistanceSensor = 0;
//
//void setup() {
//  pinMode(DistanceSensor, INPUT);
//Serial.begin(9600);  
//}
//
//void loop() {
//    buttonStateDistanceSensor = digitalRead(DistanceSensor);
//if(buttonStateDistanceSensor == LOW){
//  Serial.print("pressed");
//  }
//
//
//}


int lid = 6;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(lid, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(lid, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(lid, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
