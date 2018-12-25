#ifndef AcmeO2SensorProxy_H
#define AcmeO2SensorProxy_H

typedef struct AcmeO2SensorProxy AcmeO2SensorProxy;
struct AcmeO2SensorProxy
{
    unsigned int (*getO2Conc)(void);
    unsigned long (*getO2Flow)(void);
};

unsigned int getO2Conc();
unsigned long getO2Flow();

#endif
