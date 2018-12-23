#ifndef UltimateO2SensorProxy_H
#define UltimateO2SensorProxy_H

typedef struct AcmeO2SensorProxy AcmeO2SensorProxy;
struct AcmeO2SensorProxy
{
    unsigned int (getO2Conc*)(void);
    unsigned long (getO2Flow*)(void);
};

unsigned int accessO2Conc();
unsigned long accessO2Flow();

#endif // UltimateO2SensorProxy_H
