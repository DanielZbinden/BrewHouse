#ifndef DataBuffer_h
#define DataBuffer_h


#include "config.h"

class DataBuffer
{
  public:
    DataBuffer();
    void Add(byte data[], uint8_t dataLength);
    void Reset( void );
    void Get( void );
    
  private:
    byte buf[BUFFER_SIZE];
    uint8_t bufCount;
};
  


#endif
