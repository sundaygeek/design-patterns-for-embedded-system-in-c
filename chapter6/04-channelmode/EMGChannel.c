#include "EMGChannel.h"

static void initRelations(EMGChannel* const me);

static void cleanUpRelations(EMGChannel* const me);

void EMGChannel_Init(EMGChannel* const me) {
    initRelations(me);
}

void EMGChannel_Cleanup(EMGChannel* const me) {
    cleanUpRelations(me);
}

void EMGChannel_acquireData(EMGChannel* const me) {
    /* delegate to the appropriate part */
    EMGSensorDeviceDriver_acquireData(&me->itsEMGSensorDeviceDriver);
}

double EMGChannel_getFrequency(EMGChannel* const me) {
    return me->itsMovingAverageFilter.computedFreq;
}

long EMGChannel_getLightColor(EMGChannel* const me) {
    return me->itsCalculateColor.red<<16 + me->itsCalculateColor.green<<8 + me->itsCalculateColor.blue;
}

int EMGChannel_getVoltage(EMGChannel* const me) {
    return me->itsEMGSensorDeviceDriver.voltage;
}

void EMGChannel_setSensitivity(EMGChannel* const me, int sen) {
    EMGSensorDeviceDriver_setSensitivity(&me->itsEMGSensorDeviceDriver, sen);
}

struct CalculateColor* EMGChannel_getItsCalculateColor(const EMGChannel* const me) {
    return (struct CalculateColor*)&(me->itsCalculateColor);
}

struct ConvertToFrequency* EMGChannel_getItsConvertToFrequency(const EMGChannel* const me) {
    return (struct ConvertToFrequency*)&(me->itsConvertToFrequency);
}

struct EMGSensorDeviceDriver* EMGChannel_getItsEMGSensorDeviceDriver(const EMGChannel* const me) {
    return (struct EMGSensorDeviceDriver*)&(me->itsEMGSensorDeviceDriver);
}

struct LightDeviceDriver* EMGChannel_getItsLightDeviceDriver(const EMGChannel* const me) {
    return (struct LightDeviceDriver*)&(me->itsLightDeviceDriver);
}

struct MovingAverageFilter* EMGChannel_getItsMovingAverageFilter(const EMGChannel* const me) {
    return (struct MovingAverageFilter*)&(me->itsMovingAverageFilter);
}

EMGChannel * EMGChannel_Create(void) {
    EMGChannel* me = (EMGChannel *) malloc(sizeof(EMGChannel));
    if(me!=NULL)
        EMGChannel_Init(me);
    return me;
}

void EMGChannel_Destroy(EMGChannel* const me) {
    if(me!=NULL)
        EMGChannel_Cleanup(me);
    free(me);
}

static void initRelations(EMGChannel* const me) {
    CalculateColor_Init(&(me->itsCalculateColor));
    ConvertToFrequency_Init(&(me->itsConvertToFrequency));
    EMGSensorDeviceDriver_Init(&(me->itsEMGSensorDeviceDriver));
    LightDeviceDriver_Init(&(me->itsLightDeviceDriver));
    MovingAverageFilter_Init(&(me->itsMovingAverageFilter));
    EMGSensorDeviceDriver_setItsConvertToFrequency(&(me->itsEMGSensorDeviceDriver), &(me->itsConvertToFrequency));
    ConvertToFrequency_setItsMovingAverageFilter(&(me->itsConvertToFrequency), &(me->itsMovingAverageFilter));
    MovingAverageFilter_setItsCalculateColor(&(me->itsMovingAverageFilter), &(me->itsCalculateColor));
    CalculateColor_setItsLightDeviceDriver(&(me->itsCalculateColor), &(me->itsLightDeviceDriver));
}

static void cleanUpRelations(EMGChannel* const me) {
    MovingAverageFilter_Cleanup(&(me->itsMovingAverageFilter));
    LightDeviceDriver_Cleanup(&(me->itsLightDeviceDriver));
    EMGSensorDeviceDriver_Cleanup(&(me->itsEMGSensorDeviceDriver));
    ConvertToFrequency_Cleanup(&(me->itsConvertToFrequency));
    CalculateColor_Cleanup(&(me->itsCalculateColor));
}
