
//************************************ general Defines ************************************
#define     ON                                true
#define     OFF                               false
#define     SERIAL_SPEED                      9600//115200
#define     NORMALY_CLOSED                    1
#define     NORMALY_OPEN                      0
//************************************ Peripherie to use ************************************
#define     USE_AGITATOR
//#define     USE_ALARM

//*********************************** Defines for LM335 ***********************************
#define     KETTLE_TEMP_PIN                   A0
#define     MASH_TEMP_PIN                     A1
#define     AMBIENT_TEMP_PIN                  A2
#define     SENSOR_COUNT                      3
#define     SENSOR_PINS[]                     {A0, A1, A2}
#define     DEFAULT_AVERAGE_MODE              true
#define     DEFAULT_ACCURACY_SETTING          ONE_POINT

#define     mV_PER_K                          10
#define     SUPPLY_V                          4960//5030//4091 on PI TODO: meassure when finished
#define     ZERO_KELVIN                       273.15   
//*********************************** Defines for Pumps ***********************************
#define     KETTLE_PUMP_PIN                   9
#define     MASH_PUMP_PIN                     10
#define     PUMP_DEFAULT_STATE                NORMALY_OPEN
#define     PUMP_DEFAULT_MODE                 TWO_STATE_MODE
//*********************************** Defines for Relays **********************************
#define     HEATER_PIN                        7
#define     AGITATOR_PIN                      8
#define     ALARM_PIN                         4
#define     RELAY_DEFAULT_STATE               NORMALY_CLOSED
//*********************************** Defines for HX 711 scale **********************************
#define     DOUT_PIN                           5 // violet
#define     SCK_PIN                            6 //türkis
#define     _CALIBRATION_VALUE                -35.5//-4350.0
#define     _STABILIZINGTIME                  200
#define     _TARE                             true

//*********************************** Defines for Raspbi **********************************
#define     BUFFER_SIZE                       13
