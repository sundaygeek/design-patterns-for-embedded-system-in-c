#ifndef AcmeO2Adapter_H
#define AcmeO2Adapter_H

#include "AcmeO2SensorProxy.h"
#include "iO2Sensor.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct AcmeO2Adapter AcmeO2Adapter;
struct AcmeO2Adapter
{
    iO2Sensor* iO2Sensor;
    AcmeO2SensorProxy* itsAcmeO2SensorProxy;
};

void AcmeO2Adapter_Init(AcmeO2Adapter* const me);
void AcmeO2Adapter_Cleanup(AcmeO2Adapter* const me);

AcmeO2Adapter* AcmeO2Adapter_Create();
void AcmeO2Adapter_Destroy(AcmeO2Adapter* me);

int AcmeO2Adapter_gimmeO2Conc(AcmeO2Adapter* const me);
int AcmeO2Adapter_gimmeO2Flow(AcmeO2Adapter* const me);

#endif  //AcmeO2Adapter_H
