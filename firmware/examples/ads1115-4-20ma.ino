// This #include statement was automatically added by the Particle IDE.
#include "ads1115.h"

ADS1115 inputBoard;

float ma = 0.0;

void setup() {
    inputBoard.setAddress(0);
}

void loop() {

    //Input 1
    int16_t input_1 = inputBoard.readInput(1);
    ma = (input_1*4.00)/2130.00;

    Serial.printf("Input 1 reading: %f \n", ma);

    //Input 2
    int16_t input_2 = inputBoard.readInput(2);
    ma = (input_2*4.00)/2130.00;

    Serial.printf("Input 2 reading: %f \n", ma);
    
    //Input 3
    int16_t input_3 = inputBoard.readInput(3);
    ma = (input_3*4.00)/2130.00;

    Serial.printf("Input 3 reading: %f \n", ma);
    
    //Input 4
    int16_t input_4 = inputBoard.readInput(4);
    float ma = (input_4*4.00)/2130.00;

    Serial.printf("Input 4 reading: %f \n", ma);

    delay(1000);
}