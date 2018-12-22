#include "Sensor.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void Sensor_Init(Sensor* const me) {
    me->filterFrequency = 0;
    me->updateFrequency = 0;
    me->value = 0;
}

void Sensor_Cleanup(Sensor* const me) {
    printf("call Sensor_Cleanup\n");
    printf("nothong to cleanup\n");
}

//==========================================================================

int Sensor_getFilterFrequency(const Sensor* const me) {
    return me->filterFrequency;
}

void Sensor_setFilterFrequency(Sensor* const me, int p_filterFrequency) {
    me->filterFrequency = p_filterFrequency;
}

int Sensor_getUpdateFrequency(const Sensor* const me) {
    return me->updateFrequency;
}

void Sensor_setUpdateFrequency(Sensor* const me, int p_updateFrequency) {
    me->updateFrequency = p_updateFrequency;
}

int Sensor_getValue(const Sensor* const me) {
    return me->value;
}

int Sensor_acquireValue(Sensor* me) {
    int *r, *w;  // read and write addressed
    int j;

    switch(me->whatKindOfInterface) {
        case MEMORY_MAPPED:
            w = (int*)WRITE_ADDR;       // address to write to sensor
            *w = WRITE_MASK;            //sensor command to force a read
            for (int i = 0; i < 100; ++i)
            {
                /* wait loop */
            }
            r = (int*)READ_ADDR;        // address of returned value
            me->value = *r;
            break;
        case PORT_MAPPED:
            // me->value = inp(SENSOR_PORT);    // inp() is a compiler-specific port function
            me->value = (int)SENSOR_PORT;
            break;
    } // end switch
    return me->value;
}

//==========================================================================
Sensor* Sensor_Create(void) {
    Sensor* me = (Sensor*)malloc(sizeof(Sensor));
    if (me != NULL)
    {
        /* code */
        Sensor_Init(me);
    }
    return me;
}

void Sensor_Destroy(Sensor* const me) {
    if (me != NULL)
    {
        /* code */
        Sensor_Cleanup(me);
    }
    free(me);
}
