#ifndef EMGChannel_H
#define EMGChannel_H

#include "CalculateColor.h"
#include "ConvertToFrequency.h"
#include "EMGSensorDeviceDriver.h"
#include "LightDeviceDriver.h"
#include "MovingAverageFilter.h"

typedef struct EMGChannel EMGChannel;
struct EMGChannel {
    struct CalculateColor itsCalculateColor;
    struct ConvertToFrequency itsConvertToFrequency;
    struct EMGSensorDeviceDriver itsEMGSensorDeviceDriver;
    struct LightDeviceDriver itsLightDeviceDriver;
    struct MovingAverageFilter itsMovingAverageFilter;
};

/* Constructors and destructors:*/
void EMGChannel_Init(EMGChannel* const me);
void EMGChannel_Cleanup(EMGChannel* const me);

/* Operations */
void EMGChannel_acquireData(EMGChannel* const me);
double EMGChannel_getFrequency(EMGChannel* const me);
long EMGChannel_getLightColor(EMGChannel* const me);
int EMGChannel_getVoltage(EMGChannel* const me);
void EMGChannel_setSensitivity(EMGChannel* const me, int sen);

struct CalculateColor* EMGChannel_getItsCalculateColor(const EMGChannel* const me);
struct ConvertToFrequency* EMGChannel_getItsConvertToFrequency(const EMGChannel* const me);
struct EMGSensorDeviceDriver* EMGChannel_getItsEMGSensorDeviceDriver(const EMGChannel* const me);
struct LightDeviceDriver* EMGChannel_getItsLightDeviceDriver(const EMGChannel* const me);
struct MovingAverageFilter* EMGChannel_getItsMovingAverageFilter(const EMGChannel* const me);

EMGChannel * EMGChannel_Create(void);
void EMGChannel_Destroy(EMGChannel* const me);

#endif
