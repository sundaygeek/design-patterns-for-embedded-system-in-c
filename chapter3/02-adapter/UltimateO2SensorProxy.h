#ifndef UltimateO2SensorProxy_H
#define UltimateO2SensorProxy_H

typedef struct UltimateO2SensorProxy UltimateO2SensorProxy;
struct UltimateO2SensorProxy
{
    unsigned int (*accessO2Conc)(void);
    unsigned long (*accessGasFlow)(void);
};

unsigned int accessO2Conc();
unsigned long accessGasFlow();

#endif // UltimateO2SensorProxy_H
