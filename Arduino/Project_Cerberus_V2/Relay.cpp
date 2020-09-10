
#include "Arduino.h"
#include "Relay.h"


Relay::Relay(int pin,DefaultState defaultState)
{
  _pin = pin;
  _defaultState = defaultState;
  pinMode(_pin, OUTPUT);
  switchRelay(OFF);
}


void Relay::switchRelay(bool state) {
    bool switchTo =  (state != (bool)_defaultState);       //((state) && (_defaultState == 0)) || ((!state) && (_defaultState == 1));
    digitalWrite(_pin,switchTo);
    //return NO_ERROR;
}
