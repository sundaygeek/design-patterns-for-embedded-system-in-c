#ifndef UltimateO2Adapter_H
#define UltimateO2Adapter_H

#include "UltimateO2SensorProxy.h"
#include "iO2Sensor.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct UltimateO2Adapter UltimateO2Adapter;
struct UltimateO2Adapter
{
    iO2Sensor* iO2Sensor;
    UltimateO2SensorProxy* itsUltimateO2SensorProxy;
};

void UltimateO2Adapter_Init(UltimateO2Adapter* const me);
void UltimateO2Adapter_Cleanup(UltimateO2Adapter* const me);

int UltimateO2Adapter_gimmeO2Conc(UltimateO2Adapter* const me);
int UltimateO2Adapter_gimmeO2Flow(UltimateO2Adapter* const me);

UltimateO2Adapter* UltimateO2Adapter_Create();
void UltimateO2Adapter_Destroy(UltimateO2Adapter* me);

#endif //UltimateO2Adapter
