#include "AcmeO2Adapter.h"

void AcmeO2Adapter_Init(AcmeO2Adapter* const me) {
}
void AcmeO2Adapter_Cleanup(AcmeO2Adapter* const me) {
}

AcmeO2Adapter* AcmeO2Adapter_Create() {
    AcmeO2Adapter* me = (AcmeO2Adapter*)malloc(sizeof(AcmeO2Adapter));
    if (me != NULL)
    {
        AcmeO2Adapter_Init(me);
    }
    return me;
}

void AcmeO2Adapter_Destroy(AcmeO2Adapter* me){
    if (me != NULL)
    {
        AcmeO2Adapter_Destroy(me);
    }
    free(me);
}

int AcmeO2Adapter_gimmeO2Conc(AcmeO2Adapter* const me) {
    return me->itsAcmeO2SensorProxy->getO2Conc();
}

int AcmeO2Adapter_gimmeO2Flow(AcmeO2Adapter* const me) {
    return (me->itsAcmeO2SensorProxy->getO2Flow()*60)/100;


