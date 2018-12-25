#ifndef SensorMaster_H
#define SensorMaster_H

#include "Position.h"
struct DopplerSpeedSensor;
struct GPSPositionSensor;
struct OpticalSpeedSensor;
struct SimMutex;

typedef struct SensorMaster SensorMaster;
struct SensorMaster {
    struct DopplerSpeedSensor* itsDopplerSpeedSensor;
    struct GPSPositionSensor* itsGPSPositionSensor;
    struct OpticalSpeedSensor* itsOpticalSpeedSensor;
    struct SimMutex* itsSimMutex;
};


/* Constructors and destructors:*/

void SensorMaster_Init(SensorMaster* const me);
void SensorMaster_Cleanup(SensorMaster* const me);

/* Operations */
void SensorMaster_doppler_configure(SensorMaster* const me, short sampleRate);
void SensorMaster_doppler_disable(SensorMaster* const me);
void SensorMaster_doppler_enable(SensorMaster* const me);
double SensorMaster_doppler_getSpeed(SensorMaster* const me);
void SensorMaster_gps_activate(SensorMaster* const me);
void SensorMaster_gps_configure(SensorMaster* const me, short reqSatellites, int useFast);

void SensorMaster_gps_deactivate(SensorMaster* const me);
struct Position SensorMaster_gps_getPosition(SensorMaster* const me);
void SensorMaster_optical_configure(SensorMaster* const me, int wheelSize, int sensitivity);
void SensorMaster_optical_disable(SensorMaster* const me);
void SensorMaster_optical_enable(SensorMaster* const me);
double SensorMaster_optical_getSpeed(SensorMaster* const me);

struct DopplerSpeedSensor* SensorMaster_getItsDopplerSpeedSensor(const SensorMaster* const me);
void SensorMaster_setItsDopplerSpeedSensor(SensorMaster* const me, struct DopplerSpeedSensor* p_DopplerSpeedSensor);

struct GPSPositionSensor* SensorMaster_getItsGPSPositionSensor(const SensorMaster* const me);
void SensorMaster_setItsGPSPositionSensor(SensorMaster* const me, struct GPSPositionSensor* p_GPSPositionSensor);

struct OpticalSpeedSensor* SensorMaster_getItsOpticalSpeedSensor(const SensorMaster* const me);
void SensorMaster_setItsOpticalSpeedSensor(SensorMaster* const me, struct OpticalSpeedSensor* p_OpticalSpeedSensor);

struct SimMutex* SensorMaster_getItsSimMutex(const SensorMaster* const me);
void SensorMaster_setItsSimMutex(SensorMaster* const me, struct SimMutex* p_SimMutex);

SensorMaster * SensorMaster_Create(void);
void SensorMaster_Destroy(SensorMaster* const me);

#endif
