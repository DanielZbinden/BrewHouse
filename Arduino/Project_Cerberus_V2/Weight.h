#ifndef Weight_h
#define Weight_h

union WeightMeassurement_u{
  int val_int;
  byte val_byte[sizeof(int)];
  };
  
class Weight
{
  public:
    Weight();
    WeightMeassurement_u getWeight();
  private:
    int _pin;
    int _limit;
    // Alarm 
};


#endif
