#include "./src/Encoder/Encoder.h"
#include <Keyboard.h>
#include <Mouse.h>

/* Button Input Pins */
#define BTA_PIN A2
#define BTB_PIN A3
#define BTC_PIN 9
#define BTD_PIN 10
#define FxL_PIN A0
#define FxR_PIN A1
#define START_PIN 6

/* Software Debounce Interval */
#define DEBOUNCE 10

/* Encoder */
#define ENC_1_PIN_A 0
#define ENC_1_PIN_B 1
#define ENC_2_PIN_A 2
#define ENC_2_PIN_B 3

/* Encoder */
Encoder encLeft(ENC_1_PIN_A, ENC_1_PIN_B);
Encoder encRight(ENC_2_PIN_A, ENC_2_PIN_B);

/* Button */
unsigned int buttonPin[7] = {BTA_PIN, BTB_PIN, BTC_PIN, BTD_PIN, FxL_PIN, FxR_PIN, START_PIN};
unsigned long keyTimer[7] = {0, 0, 0, 0, 0, 0, 0};
bool buttonState[7];
bool switchType[7] = {true, true, true, true, true, true, true};
char asciiKey[7] = {0x64, 0x66, 0x6A, 0x6B, 0x6D, 0x63, 0x31};

/* Startup Loop */
void setup() {
  Keyboard.begin();
  Mouse.begin();
  pinMode(BTA_PIN, INPUT_PULLUP);
  pinMode(BTB_PIN, INPUT_PULLUP);
  pinMode(BTC_PIN, INPUT_PULLUP);
  pinMode(BTD_PIN, INPUT_PULLUP);
  pinMode(FxL_PIN, INPUT_PULLUP);
  pinMode(FxR_PIN, INPUT_PULLUP);
  pinMode(START_PIN, INPUT_PULLUP);
}

/* Main Loop */
void loop() {
  checkAllKeyEvents();
  encFuncLeft();
  encFuncRight();
}

void checkAllKeyEvents(){
  for(int i = 0; i < sizeof(buttonPin) / 2; i++){
    if(switchType[i] == true){
      if(digitalRead(buttonPin[i]) == LOW && buttonState[i] == false){
        Keyboard.press(asciiKey[i]);
        buttonState[i] = true;
        keyTimer[i] = millis();
      }
      else if(digitalRead(buttonPin[i]) == HIGH && buttonState[i] == true && millis() - keyTimer[i] > DEBOUNCE){
        Keyboard.release(asciiKey[i]);
        buttonState[i] = false;
      }
    }
    else{
      if(digitalRead(buttonPin[i]) == HIGH && buttonState[i] == false){
        Keyboard.press(asciiKey[i]);
        buttonState[i] = true;
        keyTimer[i] = millis();
      }
      else if(digitalRead(buttonPin[i]) == LOW && buttonState[i] == true && millis() - keyTimer[i] > DEBOUNCE){
        Keyboard.release(asciiKey[i]);
        buttonState[i] = false;
      }
    }
  }
}

void encFuncLeft(){
  updateMousePositionLeft();
  encLeft.write(0);
}

void encFuncRight(){
  updateMousePositionRight();
  encRight.write(0);
}

void updateMousePositionLeft(){
  Mouse.move(encLeft.read(), 0, 0);
}

void updateMousePositionRight(){
  Mouse.move(0, encRight.read(), 0);
}

