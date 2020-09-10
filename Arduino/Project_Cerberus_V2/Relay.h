#ifndef Relay_h
#define Relay_h

#include "config.h"
#include "Errors.h"

//enum DefaultState {NORMALY_OPEN=0, NORMALY_CLOSED=1}; 
typedef uint8_t DefaultState;

class Relay
{
  public:
    Relay(int pin, DefaultState defaultState);
    void switchRelay (bool state);    
  private:
    int _pin;
    DefaultState _defaultState;
    
};


#endif
