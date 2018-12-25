#include "DisplayClient.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    DisplayClient* p_DisplayClient = DisplayClient_Create();
    DisplayClient_register(p_DisplayClient);

    // DisplayClient_setItsGasSensor
    // DisplayClient_getItsGasSensor
    // DisplayClient_setItsGasData
    // DisplayClient_getItsGasData

    DisplayClient_alarm(p_DisplayClient, "fuck");

    unsigned int flow=1;
    unsigned int n2=2;
    unsigned int o2=3;

    GasSensor* p_GasSensor = (GasSensor*)malloc(sizeof(GasSensor));
    GasSensor_newData(p_GasSensor, flow, n2, o2);
    GasSensor_newData(p_GasSensor, flow, n2, o2);
    GasSensor_newData(p_GasSensor, flow, n2, o2);
    GasSensor_newData(p_GasSensor, flow, n2, o2);

    DisplayClient_Destroy(p_DisplayClient);
    return 0;
}
