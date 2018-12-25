#ifndef O2Sensor_H
#define O2Sensor_H

#include <stdio.h>
#include <stdlib.h>
#include "QueuingExample.h"

typedef struct O2Sensor O2Sensor;
struct O2Sensor {
    double conc;
    unsigned int flow;
};

/* Constructors and destructors:*/
void O2Sensor_Init(O2Sensor* const me);
void O2Sensor_Cleanup(O2Sensor* const me);

/* Operations */

void O2Sensor_getO2Data(O2Sensor* const me);
O2Sensor * O2Sensor_Create(void);
void O2Sensor_Destroy(O2Sensor* const me);

#endif
