#include "DopplerSpeedSensor.h"

void DopplerSpeedSensor_Init(DopplerSpeedSensor* const me){

}
void DopplerSpeedSensor_Cleanup(DopplerSpeedSensor* const me){

}
DopplerSpeedSensor* DopplerSpeedSensor_Create(void){
    DopplerSpeedSensor* me = (DopplerSpeedSensor*)malloc(sizeof(DopplerSpeedSensor));
    if (me != NULL)
    {
        DopplerSpeedSensor_Init(me);
    }
    return me;
}

void DopplerSpeedSensor_Destroy(DopplerSpeedSensor* const me){
    if (me != NULL)
    {
        DopplerSpeedSensor_Cleanup(me);
    }
    free(me);
}

void DopplerSpeedSensor_configure(DopplerSpeedSensor* const me, int sampleRate){

}

int DopplerSpeedSensor_getSpeed(DopplerSpeedSensor* const me){

}

void DopplerSpeedSensor_enable(DopplerSpeedSensor* const me){

}

void DopplerSpeedSensor_disable(DopplerSpeedSensor* const me){

}
