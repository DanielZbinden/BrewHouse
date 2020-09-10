//void Raspi::ParseCommand() {
//get all Sensor data
// put into buffer
// send to Pi


//   Serial.println(weightSensor.getWeight().val_int,BIN);
//   Serial.println(weightSensor.getWeight().val_byte[0],BIN);
//   Serial.println("-");
//
//  byte msg[messageLength];
//  for(uint8_t x=0; x<messageLength){}
//  uint8_t *pt;
//  *pt = &msg[0];
//  *pt = TempSensors[0].getTemp();
//  pt += sizeof(float);
//  *pt = TempSensors[1].getTemp();
//  pt += sizeof(float);
//  *pt = TempSensors[2].getTemp();
//  pt += sizeof(uint8_t);
//  *pt = 7;
//  for(int i = 0; i < messageLength; i++)
//{
//  Serial.print(msg[i],BIN);
//}
//Serial.println("-");
//
//  stringComplete = false;
//}
//void Raspi::DeParseCommand() {
//  // Chek if inputstring is full
//  if (inputString == "NA") {//Shutdown everything
//    AllOff();
//  } else {
//    //Deparse the incoming string/byte-
//  }
//}
//
//    //    String Values[Commands];
//    //    int Parameters[Commands];
//    //    int index = 0;
//    //      for(int x=0; x<Input.length();x++){
//    //        char C  = Input[x];
//    //        if(C == '/'){
//    //          index++;
//    //          }else{
//    //            Values[index] += Input[x];
//    //            }
//    //            if (index >= Commands){
//    //              //Serial.println("ERROR");
//    //              x= Input.length();}
//  for (int x = 0; x <= (sizeof(Values) / sizeof(String)); x++) {
//    Parameters[x] = Values[x].toInt();}








//void evaluate_Command(String Input) {
//  if (Input == "NA") {
//    digitalWrite(Pump_Kettle_Pin, 0);
//    digitalWrite(Pump_Mash_Pin, 0);
//    digitalWrite(Agitator_Pin, 0);
//    digitalWrite(Heat_Element_Pin, HIGH);
//  } else {
//
//    //    String Values[Commands];
//    //    int Parameters[Commands];
//    //    int index = 0;
//    //      for(int x=0; x<Input.length();x++){
//    //        char C  = Input[x];
//    //        if(C == '/'){
//    //          index++;
//    //          }else{
//    //            Values[index] += Input[x];
//    //            }
//    //            if (index >= Commands){
//    //              //Serial.println("ERROR");
//    //              x= Input.length();}
//  for (int x = 0; x <= (sizeof(Values) / sizeof(String)); x++) {
//    Parameters[x] = Values[x].toInt();
//  }



//  int j = 0;
//  int Pump_Mash_Value = Parameters[j++] * 255 / 100;
//  int Pump_Kettle_Value =  Parameters[j++] * 255 / 100;
//  int Agitator_Value =   Parameters[j++] * 255 / 100;
//  bool Heat_Element_Value = (bool)Parameters[j++];
//
//  digitalWrite(Pump_Kettle_Pin, Pump_Kettle_Value);
//  digitalWrite(Pump_Mash_Pin, Pump_Mash_Value);
//  digitalWrite(Agitator_Pin, Agitator_Value);
//  digitalWrite(Heat_Element_Pin, !Heat_Element_Value);
//
//}}
//
//void Answer() {
//  uint8_t bufLength = sizeof(float);
//  byte buf[bufLength];
//  float floatVal;
//  int meassurePins[3] = {Temp_Kettle_Pin, Temp_Mash_Pin, Temp_Ambiente_Pin};
//  
//  for (uint8_t j = 0; j < 3; j++) {
//  floatVal = getTemp(meassurePins[j]);
//  byte *b = (byte *)&floatVal;
//  buf[] = (byte)floatval;
////    for (uint8_t x = 0; x < sizeof(float); x++) {
////      buf[x]
////      b++;
////    }
//  }
//  Serial.write(buf, bufLength)
//  Serial.print();
//  Serial.print("/");
//  Serial.println(getTemp(Temp_Mash_Pin));
//  Serial.print("/");
//  Serial.println(getTemp(Temp_Ambiente_Pin));
//}
//
//
//int getTemp(int Pin) {
//  float meassure = 0;
//  static float temperature = 0;
//  meassure += (float)analogRead(Pin);
//  meassure *= SUPPLY_V;
//  meassure /= 1024.0; // meassure in mV
//  meassure /= mV_PER_K; // meassure in Kelvin
//  meassure -= ZERO_KELVIN;// Output as °C
//  temperature += meassure;
//  if (temperature != 0) {
//    temperature /= 2; // average the meassurement
//  }
//  return temperature;
//}
