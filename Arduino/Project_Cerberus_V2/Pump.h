#ifndef Pump_h
#define Pump_h

#include "config.h"
#include "Errors.h"
#include "Relay.h"


enum PumpMode {TWO_STATE_MODE, ANALOG_MODE};

class Pump
{
  public:
    Pump(int pin,DefaultState defaultState, PumpMode pumpMode);
    errors switchPump (bool state);
    errors setPump (uint8_t value);
    
  private:
    int _pin;
    PumpMode _pumpMode;
    DefaultState _defaultState;
    
};


#endif
