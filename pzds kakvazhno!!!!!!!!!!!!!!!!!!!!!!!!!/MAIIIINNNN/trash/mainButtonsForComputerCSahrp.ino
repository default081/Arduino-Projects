const int buttonPinOne = 8;     
const int buttonPinTwo = 9;     
const int buttonPinThree = 10;     
const int buttonPinReset = 11;

int isBtnOnePress = 0;
int isBtnTwoPress = 0;
int isBtnThreePress = 0;

int raspberry = 13;
int releOne = 6;
int releTwo = 7;

//const int buttonPinOne = 48;     
//const int buttonPinTwo = 46;     
//const int buttonPinThree = 44;     
//const int buttonPinReset = 42;

int buttonStateOne = 0;         
int buttonStateTwo = 0;         
int buttonStateThree = 0;         
int buttonStateReset = 0;         

void setup() {
  pinMode(buttonPinOne, INPUT);
  pinMode(buttonPinTwo, INPUT);
  pinMode(buttonPinThree, INPUT);
  pinMode(buttonPinReset, INPUT);

  pinMode(raspberry, OUTPUT);
  pinMode(releOne, OUTPUT);
  pinMode(releTwo, OUTPUT);

  Serial.begin(9600);        
}

void loop() {
  buttonStateOne = digitalRead(buttonPinOne);
  buttonStateTwo = digitalRead(buttonPinTwo);
  buttonStateThree = digitalRead(buttonPinThree);
  buttonStateReset = digitalRead(buttonPinReset);

  if (buttonStateOne == HIGH) {
    Serial.print("1");
    digitalWrite(raspberry, HIGH); // raspberry сетодиод
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
      isBtnOnePress = isBtnTwoPress = isBtnThreePress = 0;
  }


}
