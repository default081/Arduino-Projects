/*переменные кнопок и датчика*/
const int SenBtnFix = 10;
const int SenBtnOne = 9;
const int SenBtnTwo = 4;
const int DistanceSensor = 3;

/*переменные светодиодов*/
const int finalLed = 6;

/*переменные состояния кнопок*/
int buttonStateSenBtnFix = 0;
int buttonStateSenBtnOne = 0;
int buttonStateSenBtnTwo = 0;
int buttonStateDistanceSensor = 0;

int isFixDistancePressed = 0;

void setup() {
  pinMode(SenBtnFix, INPUT);
  pinMode(SenBtnOne, INPUT);
  pinMode(SenBtnTwo, INPUT);
  pinMode(DistanceSensor, INPUT);
  
  pinMode(finalLed, OUTPUT);

  Serial.begin(9600);  

}

void loop() {
  buttonStateSenBtnFix = digitalRead(SenBtnFix);
  buttonStateSenBtnOne = digitalRead(SenBtnOne);
  buttonStateSenBtnTwo = digitalRead(SenBtnTwo);
  buttonStateDistanceSensor = digitalRead(DistanceSensor);
  
  if(buttonStateSenBtnFix == HIGH && buttonStateDistanceSensor == LOW){
    isFixDistancePressed = 1;
    Serial.print(isFixDistancePressed);
  }
  else{
    isFixDistancePressed = 0;
  }
  if(isFixDistancePressed == 1 && buttonStateSenBtnOne == HIGH && buttonStateSenBtnTwo == HIGH){
    Serial.print("...................");
    digitalWrite(finalLed, HIGH);
  }
  else{
    digitalWrite(finalLed, LOW);
    }

}
