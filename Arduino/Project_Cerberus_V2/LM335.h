#ifndef LM335_h
#define LM335_h

enum AccuracySetting {HOLE_NUMMER, ONE_POINT, TWO_POINT};
union TempMeassurement_u{
  float val_float;
  byte val_byte[sizeof(float)];
  };
  
class LM335
{
  public:
    LM335(int pin, bool averageMode, AccuracySetting accuracy);
    LM335(int pin);
    TempMeassurement_u getTemp();
  private:
    int _pin;
    float _tempOld;
    bool _movingAve;
    AccuracySetting _accuracy;
    //Limit
    //Alarm
};


#endif
