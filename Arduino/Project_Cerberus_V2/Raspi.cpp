#include "Arduino.h"
#include "Raspi.h"
//#include <Utility.h>

extern String inputString;

Raspi::Raspi():
  weightSensor(DOUT_PIN, SCK_PIN),
  tempAmb  (AMBIENT_TEMP_PIN, DEFAULT_AVERAGE_MODE, DEFAULT_ACCURACY_SETTING),
  tempKettle(KETTLE_TEMP_PIN, DEFAULT_AVERAGE_MODE, DEFAULT_ACCURACY_SETTING),
  tempMash  (MASH_TEMP_PIN, DEFAULT_AVERAGE_MODE, DEFAULT_ACCURACY_SETTING),
  mashPump(MASH_PUMP_PIN, PUMP_DEFAULT_STATE),
  kettlePump(KETTLE_PUMP_PIN, PUMP_DEFAULT_STATE),
  heater(HEATER_PIN, RELAY_DEFAULT_STATE),
  agitator(AGITATOR_PIN, NORMALY_OPEN),
  //#ifdef USE_ALARM
  alarm(ALARM_PIN, RELAY_DEFAULT_STATE)
  //#endif

{
  newCommand = false;
}


void Raspi::init() {
  Serial.begin(SERIAL_SPEED);
  weightSensor.begin();
  weightSensor.start(_STABILIZINGTIME, _TARE);
    if (weightSensor.getTareTimeoutFlag()) {
    Serial.println("ERROR: Timeout, check MCU>HX711 wiring and pin designations");
  }
   weightSensor.setCalFactor(_CALIBRATION_VALUE); // set calibration value (float)
}


void Raspi::doWork() {
  // while (true) {
  if (newCommand == false) { //Waiting for stringComplete
    delay(200);
  } else {
    CommandHandler();
  }
}


void Raspi::CommandHandler() {

  if (inputString.startsWith("set")) {
    String device = inputString.substring(4, inputString.indexOf('='));
    String state = inputString.substring(inputString.indexOf('=') + 1, inputString.indexOf('\r'));
    Serial.println(device);
    if (device == "heater") {
      if (state == "true") {
        heater.switchRelay(ON);
      } else {
        heater.switchRelay(OFF);
      }
    }

    else if (device == "agitator") {
      if (state == "true") {
        agitator.switchRelay(ON);
      } else {
        agitator.switchRelay(OFF);
      }
    }

    else if (device == "alarm") {
      if (state == "true") {
        alarm.switchRelay(ON);
      } else {
        alarm.switchRelay(OFF);
      }
    }

    else if (device == "pump_mash") {
      if (state == "true") {
        mashPump.switchRelay(ON);
      } else {
        mashPump.switchRelay(OFF);
      }
    }

    else if (device == "pump_kettle") {
      if (state == "true") {
        kettlePump.switchRelay(ON);
      } else {
        kettlePump.switchRelay(OFF);
      }
    }
    
    else if (device == "weight") {
      if (state == "tare") {
      weightSensor.tareNoDelay();
      } else {
      weightSensor.setCalFactor(state.toInt());
      }
  } else {
      Serial.println("\nERROR: No such device!");
    }
  }

  else if (inputString.startsWith("get")) {
    String device = inputString.substring(4, inputString.indexOf('\n'));
    if (device == "temp_kettle" || device == "all") {
      Serial.print("temp_kettle");
      Serial.write(':');
      SendMeassurments(tempKettle.getTemp().val_float);
    }
     if (device == "temp_mash"|| device == "all") {
      Serial.print("temp_mash");
      Serial.write(':');
      SendMeassurments(tempMash.getTemp().val_float);
    }
     if (device == "temp_amb"|| device == "all") {
      Serial.print("temp_amb");
      Serial.write(':');
      SendMeassurments(tempAmb.getTemp().val_float);
    }
     if (device == "weight"|| device == "all") {
      Serial.print("weight");
      Serial.write(':');
      if(weightSensor.update()){

      SendMeassurments(weightSensor.getData()/100);
      }else{
      Serial.println("inf"); 
      }
     }
//    } else {
//      Serial.println("ERROR: No such device!");
//    }
  }

  inputString = "";
  newCommand = false;
}

void Raspi::SendMeassurments(float data) {
  Serial.println(data);
}

void Raspi::SendMeassurments(int data) {
  Serial.println(data);
}
//
//void Raspi::SendMeassurments(byte data[], uint8_t dataLength) {
//  for (uint8_t n = 0; n < dataLength; n++) {
//    Serial.write(data[n]);
//  }
//  Serial.write('\n');
//
//}
//void Raspi::GetAllMeassurments() {
//  buf.Reset();
//  for (uint8_t j = 0; j < SENSOR_COUNT; j++) {
//    Serial.println(TempSensors[j].getTemp().val_float);
//    buf.Add(TempSensors[j].getTemp().val_byte, 4);
//  }
//buffer reset
//buffer.add meas1, meas2 ....
//}
