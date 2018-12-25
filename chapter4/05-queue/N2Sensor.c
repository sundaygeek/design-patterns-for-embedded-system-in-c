#include "HeSensor.h"
#include <stdlib.h>
#include <stdio.h>

void HeSensor_Init(HeSensor* const me) {
    me->conc = 0.0;
    me->flow = 0;
}

void HeSensor_Cleanup(HeSensor* const me) {
}

/*
    getO2Data() is where the sensor class would
    actually acquire the data. Here it just
    augments it
*/
void HeSensor_getHeData(HeSensor* const me) {
    me->conc += 20;
    me->flow += 25;
}

HeSensor * HeSensor_Create(void) {
    HeSensor* me = (HeSensor *) malloc(sizeof(HeSensor));
    if(me!=NULL) {
        HeSensor_Init(me);
    }
    return me;
}

void HeSensor_Destroy(HeSensor* const me) {
    if(me!=NULL) {
        HeSensor_Cleanup(me);
    }
    free(me);
}
