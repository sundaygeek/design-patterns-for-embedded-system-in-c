#include "SensorMaster.h"
#include "DopplerSpeedSensor.h"
#include "GPSPositionSensor.h"
#include "OpticalSpeedSensor.h"
#include "SimMutex.h"

static void cleanUpRelations(SensorMaster* const me);

void SensorMaster_Init(SensorMaster* const me) {
    me->itsDopplerSpeedSensor = NULL;
    me->itsGPSPositionSensor = NULL;
    me->itsOpticalSpeedSensor = NULL;
    me->itsSimMutex = NULL;
}

void SensorMaster_Cleanup(SensorMaster* const me) {
    cleanUpRelations(me);
}

void SensorMaster_doppler_configure(SensorMaster* const me, short sampleRate) {
    SimMutex_lock(me->itsSimMutex);
    DopplerSpeedSensor_configure(me->itsDopplerSpeedSensor,sampleRate);
    SimMutex_release(me->itsSimMutex);
}

void SensorMaster_doppler_disable(SensorMaster* const me) {
    SimMutex_lock(me->itsSimMutex);
    DopplerSpeedSensor_disable(me->itsDopplerSpeedSensor);
    SimMutex_release(me->itsSimMutex);
}

void SensorMaster_doppler_enable(SensorMaster* const me) {
    SimMutex_lock(me->itsSimMutex);
    DopplerSpeedSensor_enable(me->itsDopplerSpeedSensor);
    SimMutex_release(me->itsSimMutex);
}

double SensorMaster_doppler_getSpeed(SensorMaster* const me) {
    double speed;
    SimMutex_lock(me->itsSimMutex);
    speed = DopplerSpeedSensor_getSpeed(me->itsDopplerSpeedSensor);
    SimMutex_release(me->itsSimMutex);
    return speed;
}

void SensorMaster_gps_activate(SensorMaster* const me) {
    SimMutex_lock(me->itsSimMutex);
    GPSPositionSensor_activate(me->itsGPSPositionSensor);
    SimMutex_release(me->itsSimMutex);
}

void SensorMaster_gps_configure(SensorMaster* const me, short reqSatellites, int useFast) {
    SimMutex_lock(me->itsSimMutex);
    GPSPositionSensor_configure(me->itsGPSPositionSensor,reqSatellites,useFast);
    SimMutex_release(me->itsSimMutex);
}

void SensorMaster_gps_deactivate(SensorMaster* const me) {
    SimMutex_lock(me->itsSimMutex);
    GPSPositionSensor_deactivate(me->itsGPSPositionSensor);
    SimMutex_release(me->itsSimMutex);
}

struct Position SensorMaster_gps_getPosition(SensorMaster* const me) {
    Position p;
    SimMutex_lock(me->itsSimMutex);
    p = GPSPositionSensor_getPosition(me->itsGPSPositionSensor);
    SimMutex_release(me->itsSimMutex);
    return p;
}

void SensorMaster_optical_configure(SensorMaster* const me, int wheelSize, int sensitivity) {
    SimMutex_lock(me->itsSimMutex);
    OpticalSpeedSensor_configure(me->itsOpticalSpeedSensor,wheelSize, sensitivity);
    SimMutex_release(me->itsSimMutex);
}

void SensorMaster_optical_disable(SensorMaster* const me) {
    SimMutex_lock(me->itsSimMutex);
    OpticalSpeedSensor_disable(me->itsOpticalSpeedSensor);
    SimMutex_release(me->itsSimMutex);
}

void SensorMaster_optical_enable(SensorMaster* const me) {
    SimMutex_lock(me->itsSimMutex);
    OpticalSpeedSensor_enable(me->itsOpticalSpeedSensor);
    SimMutex_release(me->itsSimMutex);
}

double SensorMaster_optical_getSpeed(SensorMaster* const me) {
    double speed;
    SimMutex_lock(me->itsSimMutex);
    speed = OpticalSpeedSensor_getSpeed(me->itsOpticalSpeedSensor);
    SimMutex_release(me->itsSimMutex);
    return speed;
}

struct DopplerSpeedSensor* SensorMaster_getItsDopplerSpeedSensor(const SensorMaster* const me) {
    return (struct DopplerSpeedSensor*)me->itsDopplerSpeedSensor;
}

void SensorMaster_setItsDopplerSpeedSensor(SensorMaster* const me, struct DopplerSpeedSensor* p_DopplerSpeedSensor) {
    me->itsDopplerSpeedSensor = p_DopplerSpeedSensor;
}

struct GPSPositionSensor* SensorMaster_getItsGPSPositionSensor(const SensorMaster* const me) {
    return (struct GPSPositionSensor*)me->itsGPSPositionSensor;
}

void SensorMaster_setItsGPSPositionSensor(SensorMaster* const me, struct GPSPositionSensor* p_GPSPositionSensor) {
    me->itsGPSPositionSensor = p_GPSPositionSensor;
}

struct OpticalSpeedSensor* SensorMaster_getItsOpticalSpeedSensor(const SensorMaster* const me) {
    return (struct OpticalSpeedSensor*)me->itsOpticalSpeedSensor;
}

void SensorMaster_setItsOpticalSpeedSensor(SensorMaster* const me, struct OpticalSpeedSensor* p_OpticalSpeedSensor) {
    me->itsOpticalSpeedSensor = p_OpticalSpeedSensor;
}

struct SimMutex* SensorMaster_getItsSimMutex(const SensorMaster* const me) {
    return (struct SimMutex*)me->itsSimMutex;
}

void SensorMaster_setItsSimMutex(SensorMaster* const me, struct SimMutex* p_SimMutex) {
    me->itsSimMutex = p_SimMutex;
}

SensorMaster * SensorMaster_Create(void) {
    SensorMaster* me = (SensorMaster *) malloc(sizeof(SensorMaster));
    if(me!=NULL)
        SensorMaster_Init(me);
    return me;
}

void SensorMaster_Destroy(SensorMaster* const me) {
    if(me!=NULL)
        SensorMaster_Cleanup(me);
    free(me);
}

static void cleanUpRelations(SensorMaster* const me) {
    if(me->itsDopplerSpeedSensor != NULL)
            me->itsDopplerSpeedSensor = NULL;
    if(me->itsGPSPositionSensor != NULL)
            me->itsGPSPositionSensor = NULL;
    if(me->itsOpticalSpeedSensor != NULL)
            me->itsOpticalSpeedSensor = NULL;
    if(me->itsSimMutex != NULL)
            me->itsSimMutex = NULL;
}
