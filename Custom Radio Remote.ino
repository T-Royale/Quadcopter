#include <VirtualWire.h>

//Button Pinout//
  const char ButtonUp = 3;
  const char ButtonDown = 4;
  const char ButtonLeft = 5;
  const char ButtonRight = 6;
//---DEBOUNCING--//
  const int DebounceDelay = 200;
//Debouncing (ButtonUp)//
  bool ButtonUpState;
  bool LastButtonUpState = true;
  unsigned long LastButtonUpTime;
//Debouncing (ButtonDown)//
  bool ButtonDownState;
  bool LastButtonDownState = true;
  unsigned long LastButtonDownTime;
//Debouncing (ButtonLeft)//
  bool ButtonLeftState;
  bool LastButtonLeftState = true;
  unsigned long LastButtonLeftTime;
//Debouncing (ButtonRight)//
  bool ButtonRightState;
  bool LastButtonRightState = true;
  unsigned long LastButtonRightTime;
//Radio Module Pinout//
  #define Radio_Tx 7
//Radio signals for each button//
  unsigned char ButtonUpSignal[] = "Up";
  unsigned char ButtonDownSignal[] = "Down";
  unsigned char ButtonLeftSignal[] = "Left";
  unsigned char ButtonRightSignal[] = "Right";
//Code Setup//
void setup() {
  vw_set_tx_pin(Radio_Tx);
  vw_setup(2000);
  pinMode(ButtonUp, INPUT);
  pinMode(ButtonDown, INPUT);
  pinMode(ButtonLeft, INPUT);
  pinMode(ButtonRight, INPUT);
  Serial.begin(9600);
}

void loop() {
  //ButtonUp Code//
    ButtonUpState = digitalRead(ButtonUp);
    if (ButtonUpState != LastButtonUpState) {
      LastButtonUpTime = millis();
    }
    if ((millis() - LastButtonUpTime) > DebounceDelay){
      LastButtonUpState = ButtonUpState;
      if (ButtonUpState == 1) {
        vw_send((uint8_t*)ButtonUpSignal, strlen((char*)ButtonUpSignal) + 1);
        Serial.println("ButtonUp is pressed");
      }
    }
  //ButtonDown Code//
    ButtonDownState = digitalRead(ButtonDown);
    if (ButtonDownState != LastButtonDownState) {
      LastButtonDownTime = millis();
    }
    if ((millis() - LastButtonDownTime) > DebounceDelay){
      LastButtonDownState = ButtonDownState;
      if (ButtonDownState == 1) {
        vw_send((uint8_t*)ButtonDownSignal, strlen((char*)ButtonDownSignal) + 1);
        Serial.println("ButtonDown is pressed");
      }
    }
  //ButtonLeft Code//
    ButtonLeftState = digitalRead(ButtonLeft);
    if (ButtonLeftState != LastButtonLeftState) {
      LastButtonLeftTime = millis();
    }
    if ((millis() - LastButtonLeftTime) > DebounceDelay){
      LastButtonLeftState = ButtonLeftState;
      if (ButtonLeftState == 1) {
        vw_send((uint8_t*)ButtonLeftSignal, strlen((char*)ButtonLeftSignal) + 1);
        Serial.println("ButtonLeft is pressed");
      }
    }
  //ButtonRight Code//
    ButtonRightState = digitalRead(ButtonRight);
    if (ButtonRightState != LastButtonRightState) {
      LastButtonRightTime = millis();
    }
    if ((millis() - LastButtonRightTime) > DebounceDelay){
      LastButtonRightState = ButtonRightState;
      if (ButtonRightState == 1) {
        vw_send((uint8_t*)ButtonRightSignal, strlen((char*)ButtonRightSignal) + 1);
        Serial.println("ButtonRight is pressed");
      }
    }
  }
