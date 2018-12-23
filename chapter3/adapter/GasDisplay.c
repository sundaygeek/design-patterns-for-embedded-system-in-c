#include "GasDisplay.h"

void displayGas(){
    iO2Sensor sensor;
    UltimateO2Adapter ultimateO2Adapter = UltimateO2Adapter_Create();
    AcmeO2Adapter acmeO2Adapter = AcmeO2Adapter_Create();
    
    int o2conc1 = AcmeO2Adapter_gimmeO2Conc(acmeO2Adapter);
    int o2flow1 = AcmeO2Adapter_gimmeO2Flow(acmeO2Adapter);

    int o2conc2 = UltimateO2Adapter_gimmeO2Conc(ultimateO2Adapter);
    int o2flow2 = UltimateO2Adapter_gimmeO2Flow(ultimateO2Adapter);

    
}
