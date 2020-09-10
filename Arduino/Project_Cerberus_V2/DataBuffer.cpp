
#include "Arduino.h"
#include "DataBuffer.h"


DataBuffer::DataBuffer()
{
  bufCount = 0;
}
    void DataBuffer::Add(byte data[], uint8_t dataLength){
        //Serial.print("Datalength:  ");
        //Serial.println(dataLength);
      if((bufCount + dataLength) < BUFFER_SIZE){
        memcpy(&buf[bufCount], &data, dataLength);
        bufCount += dataLength;
        }else{
        Serial.println("ERROR: not enough space in Buffer!!");
        }
        }
        
    void DataBuffer::Reset(){
      memset(buf, 0, sizeof(buf));
      bufCount = 0;
      }
    
    void DataBuffer::Get( void ){
      for(uint8_t x=0;x<BUFFER_SIZE;x++){
        Serial.write(buf[x]);
        }
        //Serial.println();
        }
