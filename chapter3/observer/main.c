#include "DisplayClient.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    DisplayClient* me = DisplayClient_Create();
    DisplayClient_register(me);

    // DisplayClient_setItsGasSensor
    // DisplayClient_getItsGasSensor
    // DisplayClient_setItsGasData
    // DisplayClient_getItsGasData

    DisplayClient_alarm(me, "fuck");

    unsigned int flow=1;
    unsigned int n2=2;
    unsigned int o2=3
    GasSensor_newData(me, flow, n2, o2);
    GasSensor_newData(me, flow, n2, o2);
    GasSensor_newData(me, flow, n2, o2);
    GasSensor_newData(me, flow, n2, o2);

    DisplayClient_Destroy(me);
    return 0;
}
