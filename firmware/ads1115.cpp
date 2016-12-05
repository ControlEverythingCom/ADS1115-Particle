#include "ads1115.h"

bool ADS1115::setAddress(int addressJumper){
    if(addressJumper == 1){
        address = address | 1;
    }
}

int ADS1115::readInput(int channel){
    // byte writeData[2] = {(byte)readInputSingleEnded[channel -1], (byte)(readInputSingleEnded[channel - 1]>>8)};
    if(!wireWrite(address, 0x01, readInputSingleEnded[channel -1], 2)){
        Serial.println("WireWrite failed");
    }
    delay(50);
    if(!wireRead(address, 0x00, localReadBuf, 2)){
        Serial.println("WireRead failed");
    }
    
    uint16_t raw_adc = (localReadBuf[0] << 8) | localReadBuf[1];

    return raw_adc;
}

bool ADS1115::wireWrite(int addr, int reg, uint16_t value, int len){
    if (!Wire.isEnabled()) {
        Wire.begin();
    }
    Wire.beginTransmission(addr);
    Wire.write((uint8_t)reg);
    Wire.write((uint8_t)(value>>8));
    Wire.write((uint8_t)(value & 0xFF));
    byte status = Wire.endTransmission();
    if(status == 0){
        return true;
    }else{
        return false;
    }
}

bool ADS1115::wireRead(int addr, int reg, int* readBuff, int returnLen){
    int buf[returnLen];
    if (!Wire.isEnabled()) {
        Wire.begin();
    }
    Wire.beginTransmission(addr);
    Wire.write(reg);
    byte status = Wire.endTransmission();
    if(status != 0){
        return false;
    }
    Wire.requestFrom(addr, returnLen);
    unsigned long startTime = millis();
    while(Wire.available() != returnLen && millis()<startTime+timeout);
    if(Wire.available() != returnLen){
        return false;
    }
    for(int i = 0; i < returnLen; i++){
        readBuff[i] = Wire.read();
        // Serial.printf("read: %i \n", readBuff[i]);
    }
    return true;
}