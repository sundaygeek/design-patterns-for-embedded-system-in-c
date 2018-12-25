#ifndef BreathingCircuitSensor_H
#define BreathingCircuitSensor_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BreathingCircuitSensor BreathingCircuitSensor;
struct BreathingCircuitSensor
{
    int data;
    int state;
};

void BreathingCircuitSensor_Init(BreathingCircuitSensor* const me);
void BreathingCircuitSensor_Cleanup(BreathingCircuitSensor* const me);

BreathingCircuitSensor* BreathingCircuitSensor_Create();
void BreathingCircuitSensor_Destroy(BreathingCircuitSensor* me);

int BreathingCircuitSensor_getData(BreathingCircuitSensor* const me);
int BreathingCircuitSensor_getState(BreathingCircuitSensor* const me);

#endif
