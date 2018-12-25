#include "SensorThread.h"
/*
    updateData runs every period of the sensor thread
    and calls the getXXData() function of each of
    its sensors, then uses a random number generator
    to decide which data should be published to the
    GasDataQueue.
*/
void SensorThread_updateData(SensorThread* const me) {
    unsigned char success;
    GasData g;

    GasData_Init(&g);

    O2Sensor_getO2Data(&(me->itsO2Sensor));
    N2Sensor_getN2Data(&(me->itsN2Sensor));
    HeSensor_getHeData(&(me->itsHeSensor));

    if (rand() > RAND_MAX / 3) {
        g.gType = HE_GAS;
        g.conc = me->itsHeSensor.conc;
        g.flowInCCPerMin = me->itsHeSensor.flow;
        success = GasDataQueue_insert(me->itsGasDataQueue, g);
        if (!success)
            printf("Helium Gas Data queue insertion failed!\n");
    };

    if (rand() > RAND_MAX / 3) {
        g.gType = N2_GAS;
        g.conc = me->itsN2Sensor.conc;
        g.flowInCCPerMin = me->itsN2Sensor.flow;
        success = GasDataQueue_insert(me->itsGasDataQueue, g);
        if (!success)
            printf("Nitrogen Gas Data queue insertion failed!\n");
    };

    if (rand() > RAND_MAX / 3) {
        g.gType = O2_GAS;
        g.conc = me->itsO2Sensor.conc;
        g.flowInCCPerMin = me->itsO2Sensor.flow;
        success = GasDataQueue_insert(me->itsGasDataQueue, g);
        if (!success)
            printf("Oxygen Gas Data queue insertion failed! \n");
    }
}
