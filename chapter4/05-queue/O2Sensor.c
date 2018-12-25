#include "O2Sensor.h"
#include <stdlib.h>
#include <stdio.h>

void O2Sensor_Init(O2Sensor* const me) {
    me->conc = 0.0;
    me->flow = 0;
}

void O2Sensor_Cleanup(O2Sensor* const me) {
}

/*
    getO2Data() is where the sensor class would
    actually acquire the data. Here it just
    augments it
*/
void O2Sensor_getO2Data(O2Sensor* const me) {
    me->conc += 20;
    me->flow += 25;
}

O2Sensor * O2Sensor_Create(void) {
    O2Sensor* me = (O2Sensor *) malloc(sizeof(O2Sensor));
    if(me!=NULL) {
        O2Sensor_Init(me);
    }
    return me;
}

void O2Sensor_Destroy(O2Sensor* const me) {
    if(me!=NULL) {
        O2Sensor_Cleanup(me);
    }
    free(me);
}
