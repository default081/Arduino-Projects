// Main program
const int buttonPinOne = 8;     
const int buttonPinTwo = 9;     
const int buttonPinThree = 10;     
const int buttonPinReset = 11;

int isBtnOnePress = 0;
int isBtnTwoPress = 0;
int isBtnThreePress = 0;

int releOne = 6;
int releTwo = 7;

int lastLed = 13;
int lastLedStatus = 0;

int buttonStateOne = 0;         
int buttonStateTwo = 0;         
int buttonStateThree = 0;         
int buttonStateReset = 0;         

void setup() {
  pinMode(buttonPinOne, INPUT);
  pinMode(buttonPinTwo, INPUT);
  pinMode(buttonPinThree, INPUT);
  pinMode(buttonPinReset, INPUT);

  pinMode(releOne, OUTPUT);
  pinMode(releTwo, OUTPUT);
  pinMode(lastLed, OUTPUT);


  Serial.begin(9600);        
}

void loop() {
  buttonStateOne = digitalRead(buttonPinOne);
  buttonStateTwo = digitalRead(buttonPinTwo);
  buttonStateThree = digitalRead(buttonPinThree);
  buttonStateReset = digitalRead(buttonPinReset);

  if(lastLedStatus == 0){
    digitalWrite(lastLed, HIGH);
  }
  else{
    digitalWrite(lastLed, LOW);
  }

  if (buttonStateOne == HIGH) {
    Serial.print("1");
    lastLedStatus = 1; // если унопка нажата, гасим светодиод
    isBtnOnePress = 1;
    delay(250);
  } 
  if (buttonStateTwo == HIGH) {
    Serial.print("2");
    isBtnTwoPress = 1;
    delay(250);
  } 
  if (buttonStateThree == HIGH) {
    Serial.print("3");
    isBtnThreePress = 1;
    delay(250);
  } 

  if (buttonStateReset == HIGH) {
    Serial.print("5");
    delay(250);
  } 


  if(isBtnOnePress && isBtnTwoPress && isBtnThreePress){
      delay(60000);
      digitalWrite(releOne, HIGH);
      digitalWrite(releTwo, HIGH);
      delay(5000);
      digitalWrite(releOne, LOW);
      delay(60000);
      digitalWrite(releTwo, LOW);
      lastLedStatus = 0; // Зажигаем светодиод
      isBtnOnePress = isBtnTwoPress = isBtnThreePress = 0;
  }


}
