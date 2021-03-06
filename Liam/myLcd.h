/*
 Liam - DIY Robot Lawn Mower

 LCD Display Library

 ======================
  Licensed under GPLv3
 ======================
*/

#include <Arduino.h>
#include <Wire.h>  // For LCD
#include <LiquidCrystal_I2C.h>
#include "Definition.h"
#include "Wheelmotor.h"
#include "CutterMotor.h"
#include "BWFSensor.h"
#include "MotionSensor.h"
#include "Battery.h"
#include "MyDisplay.h"

#ifndef _MYLCD_H_
#define _MYLCD_H_

class myLCD : public MYDISPLAY
{
  public:
    myLCD(BATTERY* batt, WHEELMOTOR* left, WHEELMOTOR* right, CUTTERMOTOR* cut, BWFSENSOR* bwf, MOTIONSENSOR* comp, int* state);

    boolean initialize();

    size_t write(uint8_t);
    void setCursor(int col, int row);
    void clear();
    void blink();

  private:
    LiquidCrystal_I2C lcd;
    int current_row;
    int current_col;
    const int max_rows = 4;
    const int max_cols = 20;
};

#endif /* _MYLCD_H_ */
