const int buttonPinOne = 8;     
const int buttonPinTwo = 9;     
const int buttonPinThree = 10;     
const int buttonPinReset = 11;

int buttonStateOne = 0;         
int buttonStateTwo = 0;         
int buttonStateThree = 0;         
int buttonStateReset = 0;         

void setup() {
  pinMode(buttonPinOne, INPUT);
  pinMode(buttonPinTwo, INPUT);
  pinMode(buttonPinThree, INPUT);
  pinMode(buttonPinReset, INPUT);

  Serial.begin(9600);        
}

void loop() {
  buttonStateOne = digitalRead(buttonPinOne);
  buttonStateTwo = digitalRead(buttonPinTwo);
  buttonStateThree = digitalRead(buttonPinThree);
  buttonStateReset = digitalRead(buttonPinReset);

  if (buttonStateOne == HIGH) {
    Serial.print("1");
    delay(250);
  } 
  if (buttonStateTwo == HIGH) {
    Serial.print("2");
    delay(250);
  } 
  if (buttonStateThree == HIGH) {
    Serial.print("3");
    delay(250);
  } 

  if (buttonStateReset == HIGH) {
    Serial.print("5");
    delay(250);
  } 


}
