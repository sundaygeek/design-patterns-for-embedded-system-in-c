#include "GPSPositionSensor.h"

void GPSPositionSensor_Init(GPSPositionSensor* const me){

}
void GPSPositionSensor_Cleanup(GPSPositionSensor* const me){

}

GPSPositionSensor* GPSPositionSensor_Create(void){
    GPSPositionSensor* me = (GPSPositionSensor*)malloc(sizeof(GPSPositionSensor));
    if (me != NULL)
    {
        GPSPositionSensor_Init(me);
    }
    return me;
}
void GPSPositionSensor_Destroy(GPSPositionSensor* const me){
    if (me != NULL)
    {
        GPSPositionSensor_Cleanup(me);
    }
    free(me);
}

void GPSPositionSensor_configure(GPSPositionSensor* const me, int reqSatellites, int useFast){

}

void GPSPositionSensor_activate(GPSPositionSensor* const me){

}
void GPSPositionSensor_deactivate(GPSPositionSensor* const me){

}

int GPSPositionSensor_getPosition(GPSPositionSensor* const me){

}
