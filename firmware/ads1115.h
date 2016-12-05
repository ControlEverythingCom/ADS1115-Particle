#include "spark_wiring_i2c.h"
#include "spark_wiring_constants.h"
#include "spark_wiring.h"
#include "spark_wiring_usbserial.h"

class ADS1115{
public:
    bool setAddress(int addressJumper);
    int readInput(int channel);
private:
    int address = 0x48;
    unsigned long timeout = 100;
    bool inFailureMode = false;
    bool wireWrite(int addr, int reg, uint16_t value, int len);
    bool wireRead(int addr, int reg, int* readBuff, int returnLen);
    int configReg = 0x01;
    int inRead[4][2] = {{0x84, 0x83}, {0x94, 0x83}, {0xA4, 0x83}, {0xB4, 0x83}};
    int readCommand[1] = {0x00};
    
    int localReadBuf[2];
    
    uint16_t readInputSingleEnded[4] = {49539, 53635, 57731, 61827};

};