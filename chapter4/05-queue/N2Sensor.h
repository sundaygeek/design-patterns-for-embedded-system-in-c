#ifndef N2Sensor_H
#define N2Sensor_H

#include <stdio.h>
#include <stdlib.h>
#include "QueuingExample.h"

typedef struct N2Sensor N2Sensor;
struct N2Sensor {
    double conc;
    unsigned int flow;
};

/* Constructors and destructors:*/
void N2Sensor_Init(N2Sensor* const me);
void N2Sensor_Cleanup(N2Sensor* const me);

/* Operations */

void N2Sensor_getN2Data(N2Sensor* const me);
N2Sensor * N2Sensor_Create(void);
void N2Sensor_Destroy(N2Sensor* const me);

#endif
