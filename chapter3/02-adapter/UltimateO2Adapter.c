#include "UltimateO2Adapter.h"

void UltimateO2Adapter_Init(UltimateO2Adapter* const me){
    me->itsUltimateO2SensorProxy = (UltimateO2SensorProxy*)malloc(sizeof(UltimateO2SensorProxy));
    if (me->itsUltimateO2SensorProxy != NULL)
    {
        me->itsUltimateO2SensorProxy->accessO2Conc = accessO2Conc;
        me->itsUltimateO2SensorProxy->accessGasFlow = accessGasFlow;
    }
}

void UltimateO2Adapter_Cleanup(UltimateO2Adapter* const me){
}

UltimateO2Adapter* UltimateO2Adapter_Create(){
    UltimateO2Adapter* me = (UltimateO2Adapter*)malloc(sizeof(UltimateO2Adapter));
    if (me != NULL)
    {
        UltimateO2Adapter_Init(me);
    }
    return me;
}

void UltimateO2Adapter_Destroy(UltimateO2Adapter* me){
    if (me != NULL)
    {
        UltimateO2Adapter_Destroy(me);
    }
    free(me);
}

int UltimateO2Adapter_gimmeO2Conc(UltimateO2Adapter* const me) {
    return (int)(me->itsUltimateO2SensorProxy->accessO2Conc()*100);
}

int UltimateO2Adapter_gimmeO2Flow(UltimateO2Adapter* const me) {
    double totalFlow;
    // convert from liters/hr to cc/min
    totalFlow = me->itsUltimateO2SensorProxy->accessGasFlow() * 1000.0/60.0;
    // now return the portion of the flow due to oxygen
    // and return it as an integer
    return (int)(totalFlow * me->itsUltimateO2SensorProxy->accessO2Conc());
}
