const int svtOne = 13;
const int svtTwo = 12;
const int svtTwelve = 11;

const int svtEleven = 10;
const int svtThirteen = 9;
const int svtFourteen = 8; // будет монитром nextion

const int btnOne = 2;
const int btnTwo = 3;
const int btnFix = 4;

int btnOneStatus = 0;
int btnTwoStatus = 0;
int btnFixStatus = 0;

int oneRazr = 0;
int isBtnTwoPres = 0;
int isBtnTwoPres2 = 0;

void setup() {
  pinMode(svtOne, OUTPUT);
  pinMode(svtTwo, OUTPUT);
  pinMode(svtTwelve, OUTPUT);
  pinMode(svtEleven, OUTPUT);
  pinMode(svtThirteen, OUTPUT);
  pinMode(svtFourteen, OUTPUT);

  pinMode(btnOne, INPUT);
  pinMode(btnTwo, INPUT);
  pinMode(btnFix, INPUT);

  Serial.begin(9600); 
}

void loop(){
  btnOneStatus = digitalRead(btnOne);
  btnTwoStatus = digitalRead(btnTwo);
  btnFixStatus = digitalRead(btnFix);
  

  if(isBtnTwoPres2 == 0){
      digitalWrite(svtOne, HIGH);
      delay(300);
      digitalWrite(svtOne, LOW);
      delay(300);
  }

  /*проверяем нажата ли кнопка 2 для зажиганмя svtTwelve через переменную isBtnTwoPres*/
  if(isBtnTwoPres == 0){
    digitalWrite(svtTwelve, HIGH);
  }
  if(isBtnTwoPres == 1){
    digitalWrite(svtTwelve, LOW);
  }
  
  /*проверяем нажата ли кнопка btnFix и в завичисомти от этого даем красный свет кнопке btnOne*/  
  if(btnFixStatus == LOW){
    digitalWrite(svtTwo, HIGH);
    oneRazr = 0;
  }
  else{
    oneRazr = 1;
    digitalWrite(svtTwo, LOW);
  }
  // для резета!!!!!!!!!!!!!!!!!!!!!!!!!
  if(btnOneStatus == HIGH && oneRazr == 0){
     oneRazr = 0;
     isBtnTwoPres = 0;
     isBtnTwoPres2 = 0;
     digitalWrite(svtEleven, LOW);
     digitalWrite(svtTwo, HIGH);
     digitalWrite(svtThirteen, LOW);
     digitalWrite(svtFourteen, LOW);
  }
  
  /*если нажата кновка btnTwo то загараем svtEleven, гашу svtTwelve*/
  /*если нажали btnTwo и переманная которая отвечает за нажатие фикстрованной btn ==  high*/
  if(btnTwoStatus == HIGH && oneRazr == 1){
    digitalWrite(svtEleven, HIGH);
    digitalWrite(svtOne, HIGH);
    isBtnTwoPres = 1;
    delay(8000);
    digitalWrite(svtEleven, HIGH);
    isBtnTwoPres2 = 1;
    digitalWrite(svtThirteen, HIGH);
    digitalWrite(svtFourteen, HIGH);
  }
  
}
