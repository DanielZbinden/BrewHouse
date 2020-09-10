
#include "Arduino.h"
#include "LM335.h"
#include "config.h"
LM335::LM335(int pin, bool averageMode, AccuracySetting accuracy)
{
  _pin = pin;
  _movingAve = averageMode;
  _accuracy = accuracy;
  pinMode(_pin, INPUT);
}
LM335::LM335(int pin):LM335(pin, DEFAULT_AVERAGE_MODE, DEFAULT_ACCURACY_SETTING){ //TODO: implement overload
  //LM335::LM335(pin, DEFAULT_AVERAGE_MODE, DEFAULT_ACCURACY_SETTING);
  }
  
TempMeassurement_u LM335::getTemp() {
  float meassure = 0;
  TempMeassurement_u meas;
  meassure  = (float)analogRead(_pin);
  meassure *= SUPPLY_V;
  meassure /= 1024.0; // meassure in mV
  meassure /= mV_PER_K; // meassure in Kelvin
  meassure -= ZERO_KELVIN;// Output as °C

  if (_movingAve) {
    meassure = (meassure + _tempOld) / 2;
    _tempOld = meassure;
  }
  switch (_accuracy) {
    case HOLE_NUMMER:
      meassure = (float)round(meassure);
      break;
    case ONE_POINT:
      meassure = (float)round(10 * meassure) / 10;
      break;
    case TWO_POINT:
      break;
  }
  meas.val_float = meassure;
  return meas;
}
