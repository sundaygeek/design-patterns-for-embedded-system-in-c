#include "BreathingCircuitSensor.h"

void BreathingCircuitSensor_Init(BreathingCircuitSensor* const me){

}
void BreathingCircuitSensor_Cleanup(BreathingCircuitSensor* const me){

}

BreathingCircuitSensor* BreathingCircuitSensor_Create(){
    BreathingCircuitSensor* me = (BreathingCircuitSensor*)malloc(sizeof(BreathingCircuitSensor));
    if (me != NULL)
    {
        BreathingCircuitSensor_Init(me);
    }
    return me;
}

void BreathingCircuitSensor_Destroy(BreathingCircuitSensor* me){
    if (me != NULL)
    {
        BreathingCircuitSensor_Cleanup(me);
    }
    free(me);
}

int BreathingCircuitSensor_getData(BreathingCircuitSensor* const me){

}

int BreathingCircuitSensor_getState(BreathingCircuitSensor* const me){

}
