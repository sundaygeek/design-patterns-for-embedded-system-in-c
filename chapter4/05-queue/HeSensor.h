#ifndef HeSensor_H
#define HeSensor_H

#include <stdio.h>
#include <stdlib.h>
#include "QueuingExample.h"

typedef struct HeSensor HeSensor;
struct HeSensor {
    double conc;
    unsigned int flow;
};

/* Constructors and destructors:*/
void HeSensor_Init(HeSensor* const me);
void HeSensor_Cleanup(HeSensor* const me);

/* Operations */

void HeSensor_getHeData(HeSensor* const me);
HeSensor * HeSensor_Create(void);
void HeSensor_Destroy(HeSensor* const me);

#endif
