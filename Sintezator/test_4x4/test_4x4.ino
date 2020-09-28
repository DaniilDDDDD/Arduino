#include <Keyboard.h>

int debounce = 300; // set this to the lowest value that gives the best result
const int row1 = 24;
const int row2 = 26;
const int row3 = 28;
const int row4 = 30;
const int colA = 25;
const int colB = 27;
const int colC = 29;
const int colD = 31;
const int ledPin = 13; // onboard LED

void setup(){
Serial.begin(9600);
pinMode(row1, OUTPUT);
pinMode(row2, OUTPUT);
pinMode(row3, OUTPUT);
pinMode(row4, OUTPUT);
pinMode(colA, INPUT_PULLUP);
pinMode(colB, INPUT_PULLUP);
pinMode(colC, INPUT_PULLUP);
pinMode(colD, INPUT_PULLUP);
//
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, LOW); // turn LED off
}

void loop(){

boolean r1 = digitalRead(row1);
boolean c1 = digitalRead(colA);

if (r1 && c1)
  Serial.print("Button 1.1 is pressed");
}
