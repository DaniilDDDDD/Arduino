#include <Keypad.h>

//joystick
const int joyStickButton = 8;
const int pinX = A0;
const int pinY = A1;

const int bzzz = DAC0;


//4x4 buttons matrix
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {24, 26, 28, 30}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {25, 27, 29, 31}; //connect to the column pinouts of the keypad

boolean pressed_buttons[ROWS][COLS] = {
  {false,false,false,false},
  {false,false,false,false},
  {false,false,false,false},
  {false,false,false,false}
};

int herz = 2000;
int t0 = 0;
int val;
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(joyStickButton, INPUT);
//  digitalWrite(pinX, HIGH);
  
  analogWriteResolution(8);
  analogReadResolution(12);
  Serial.begin(9600);
}


void loop(){
  int val = 4095;
  char customKey = customKeypad.getKey();

  
  switch(customKey){
    case '1':{
      pressed_buttons[0][0]=!pressed_buttons[0][0];
      break;
    }
    case '2':{
      pressed_buttons[0][1]=!pressed_buttons[0][1];
      break;
      }
      case '3':{
      pressed_buttons[0][2]=!pressed_buttons[0][2];
      break;
      }
      case '4':{
      pressed_buttons[0][3]=!pressed_buttons[0][3];
      break;
      }
      
    default:
    {
      if (pressed_buttons[0][1]){
        analogWrite(bzzz,int((micros()*herz % 1000000)/1000000.00 + 0.5)*val);
        }
//      else analogWrite(13, LOW); эту хуйню не раскоменчивать
      if (pressed_buttons[0][0]){
        analogWrite(bzzz,int((sin(2*3.14*micros()/1000000.00*herz)+1)*(val/2)));
      }
//      else analogWrite(13, LOW); и эту тоже
      if (pressed_buttons[0][2]){
        analogWrite(bzzz,int(((-abs(micros()*herz % 1000000/1000000.00-0.5))*2+1)*val));
      }
      if (pressed_buttons[0][3]){
        analogWrite(bzzz,int(micros()*herz % 1000000/1000000.00*val));
      }
      else analogWrite(bzzz, LOW);
    }
    break;
  }
  
  if ((millis()-t0) == 10)
  {
    t0 = millis();
    herz--;
    if (herz <= 1)herz = 2000;
  }
}  

/*
void loop(){
  int ledState = digitalRead(joyStickButton); // считываем состояние кнопки
  digitalWrite(13, ledState);
  int X = analogRead(pinX);
  int Y = analogRead(pinY);
  Serial.print(X); // Выводим значение в Serial Monitor
  Serial.print("\t"); // табуляция
  Serial.println(Y);
}


void loop() {
  char customKey = customKeypad.getKey();
  Serial.write(customKey);

  switch(customKey){
     case '1':{
      sample = 0;
      pressed_buttons[0][0];
      break;
      }
      case '2':{
      sample = 1;
      pressed_buttons[0][1];
      break;
      }
      case '3':{
      sample = 2;
      pressed_buttons[0][2];
      break;
      }
      case 'A':{
      sample = 3;
      pressed_buttons[0][3];
      break;
      }
      case 'D':{
      sample = 4;
      pressed_buttons[3][3];
      break;
      }
      case '*':{
      add +=1;
      pressed_buttons[3][3];
      break;
      }
      case '#':{
      add-=1;
      pressed_buttons[3][3];
      break;
      }
    };
    
  if (add<1) fr = 1.00/(1.00+abs(add));
  else fr = add;
  analogWrite(13, waveformsTable[sample][int(i)]);
  analogWrite(DAC1, waveformsTable[sample][int(i)]);

  i+=fr;
  Serial.println(fr);
  if (i>=maxSamplesNum)
    i=0;
  
  delayMicroseconds(0);
}*/
