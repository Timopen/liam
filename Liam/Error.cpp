/*
 Liam - DIY Robot Lawn Mower

 Error Handler Library

 ======================
  Licensed under GPLv3
 ======================
*/

#include "Error.h"

ERROR::ERROR(MYDISPLAY* display_, int led_pin_, CONTROLLER* Mower_, MODEMANAGER* stateManager_) {
  display = display_;
  led_pin = led_pin_;
  stateManager = stateManager_;
  Mower = Mower_;
}

String ERROR::errorMessage(int error_number)
{
  switch(error_number)
  {
// 16 characters should fit on almost any LCD
// 20 should fit on most
//           F("1234567890123456xxxx")
    case ERROR_OUTSIDE:
      return F("OUTSIDE BWF");
    case ERROR_OVERLOAD:
      return F("WHEEL OVERLOAD");
    case ERROR_TILT:
      return F("TILTED");
    case ERROR_LIFT:
      return F("FRONT LIFTED");
    case ERROR_BUMPERSTUCK:
      return F("BUMPER STUCK");
    case ERROR_FATAL_TIMEOUT:
      return F("FATAL TIMEOUT");
    default:
      return F("UNKNOWN ERROR");
  }
}

void ERROR::flag(int error_number) {
  stateManager->setMode(CutterModes::HOLD_FOR_ERROR);
  Mower->stopCutter();
  Mower->stop();
  display->clear();

  display->print("ERROR!");
  display->print("\n");
  display->print(errorMessage(error_number));
  error = error_number;


}

void ERROR::show(){
  for(int i = 0; i < error; i++) {
    digitalWrite(led_pin, HIGH);
    delay(500);
    digitalWrite(led_pin, LOW);
    delay(500);
  }
  delay(2000);
}

String ERROR::getErrorMsg(){
  return errorMessage(error);
}