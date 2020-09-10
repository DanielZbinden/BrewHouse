
#include "Arduino.h"
#include "Pump.h"


Pump::Pump(int pin,DefaultState defaultState, PumpMode pumpMode)
{
  _pin = pin;
  _pumpMode = pumpMode;
  _defaultState = defaultState;
  pinMode(_pin, OUTPUT);
  switchPump(OFF);
}


errors Pump::switchPump(bool state) {
   bool switchTo = ((state) && (_defaultState == 0)) || ((!state) && (_defaultState == 1));
  if(_pumpMode == TWO_STATE_MODE){
    digitalWrite(_pin,switchTo);
    return NO_ERROR;
    }else{
    analogWrite(_pin,255*switchTo);
    return PUMP_ERROR;
}}

errors Pump::setPump(uint8_t value) { //TODO: Max, Min value
  if(_pumpMode == ANALOG_MODE){
    analogWrite(_pin,value);
    return NO_ERROR;
    }else{
  return PUMP_ERROR;
}}
