#ifndef Raspi_h
#define Raspi_h

#include "Errors.h"
#include "LM335.h"
//#include "Pump.h"
#include "Relay.h"
#include <HX711_ADC.h>
//#include "Weight.h"
//#include "DataBuffer.h"
#include "config.h"




//const uint8_t     COMMAND_PIN_ORDER[]               {KETTLE_PUMP_PIN, MASH_PUMP_PIN, HEATER_PIN, AGITATOR_PIN, 0, 0, 0, 0};
//enum TempSensors {TEMP_KETTLE = 0, TEMP_MASH = 1, TEMP_AMBIENTE = 2};


class Raspi
{
  public:
    Raspi();
    //byte CommandByte;
    bool newCommand;
    void init();
//    void deinit();
    void configure();
    void doWork();

  private:
    //uint8_t messageLength;
    //DataBuffer buf;

    HX711_ADC weightSensor;
    //Weight weightSensor;
    LM335 tempAmb;
    LM335 tempKettle;
    LM335 tempMash;
    Relay mashPump;
    Relay kettlePump;
    Relay heater;
    Relay agitator;
    Relay alarm;
    
    //void GetCommand();
    void CommandHandler();
    void SendMeassurments(int data);
    void SendMeassurments(float data);
    //void SendMeassurments(byte data[], uint8_t dataLength);
    //void GetAllMeassurments();
};



#endif
