/*программа в которой фиксированая кнопка стала обычной*/

/*переменные кнопок и датчика*/
const int SenBtnFix = 7; // 8
const int SenBtnOne = 3; // 4
const int SenBtnTwo = 4; // 5
const int DistanceSensor = 2; // 3

/*переменные светодиодов*/
const int finalLed = 5; // 6
const int fixedLed = 6;// 7
const int ledSevenOne = 11; // 12
const int ledSevenTwo = 10; // 11
const int ledSevenThree = 9; // 10
const int ledSevenFour = 8; // 9

/*переменные состояния кнопок*/
int buttonStateSenBtnFix = 0;
int buttonStateSenBtnOne = 0;
int buttonStateSenBtnTwo = 0;
int buttonStateDistanceSensor = 0;

int isFixDistancePressed = 0;
int isFixbtnPressed = 0;

void setup() {
  pinMode(SenBtnFix, INPUT);
  pinMode(SenBtnOne, INPUT);
  pinMode(SenBtnTwo, INPUT);
  pinMode(DistanceSensor, INPUT);
  
  pinMode(finalLed, OUTPUT);
  pinMode(fixedLed, OUTPUT);
  pinMode(ledSevenOne, OUTPUT);
  pinMode(ledSevenTwo, OUTPUT);
  pinMode(ledSevenThree, OUTPUT);
  pinMode(ledSevenFour, OUTPUT);

  Serial.begin(9600);  

}

void loop() {
  buttonStateSenBtnFix = digitalRead(SenBtnFix);
  buttonStateSenBtnOne = digitalRead(SenBtnOne);
  buttonStateSenBtnTwo = digitalRead(SenBtnTwo);
  buttonStateDistanceSensor = digitalRead(DistanceSensor);

/*блок с низу отвечает за дисплей передвинул из за того что дисплей зажигается после светодиода*/
  if(buttonStateSenBtnOne == HIGH){
    digitalWrite(ledSevenThree, HIGH);
  }
  else if(buttonStateSenBtnTwo == HIGH){
    digitalWrite(ledSevenFour, HIGH);
  }
  else if(buttonStateSenBtnTwo == HIGH && buttonStateSenBtnOne == HIGH){
    digitalWrite(ledSevenThree, LOW);
    digitalWrite(ledSevenFour, LOW);
    digitalWrite(ledSevenThree, HIGH);
    digitalWrite(ledSevenFour, HIGH);
  }
  else{
    digitalWrite(ledSevenThree, LOW);
    digitalWrite(ledSevenFour, LOW);
  } 
  /*-------------------------*/

  
  if(buttonStateSenBtnFix == HIGH){
    isFixbtnPressed = 1;
    digitalWrite(fixedLed, HIGH);
    delay(500);
    digitalWrite(fixedLed, LOW);
  }
 
  if(isFixbtnPressed == 1 && buttonStateDistanceSensor == LOW){
    Serial.print(isFixbtnPressed);
    isFixDistancePressed = 1;
  }
  else{
    isFixDistancePressed = 0;
  }
  if(isFixDistancePressed == 1 && buttonStateSenBtnOne == HIGH && buttonStateSenBtnTwo == HIGH){
    digitalWrite(finalLed, LOW); /*поменяли high и low*/
    delay(7000);
  }
  else{
    digitalWrite(finalLed, HIGH);
    }


  /*робота с семи контаутнами светодиодами*/
  if(buttonStateSenBtnFix == HIGH){
    digitalWrite(ledSevenOne, HIGH);
  }
  else{
    digitalWrite(ledSevenOne, LOW);
  }
  if(buttonStateDistanceSensor == LOW){
    digitalWrite(ledSevenTwo, HIGH);
  }
  else{
    digitalWrite(ledSevenTwo, LOW);
  }

  /*reset button*/
  if(digitalRead(A1) == HIGH)  
  {
    isFixbtnPressed = LOW;
    isFixDistancePressed = 0;
    isFixDistancePressed = 0;
    digitalWrite(ledSevenOne, LOW);
    digitalWrite(ledSevenThree, LOW);
    digitalWrite(ledSevenFour, LOW);
  }

}
