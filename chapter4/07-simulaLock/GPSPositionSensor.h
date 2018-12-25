#ifndef GPSPositionSensor_H
#define GPSPositionSensor_H

typedef struct GPSPositionSensor GPSPositionSensor;
struct GPSPositionSensor
{
    int reqSatellites;
    int useFast;
    int position;
};

void GPSPositionSensor_Init(GPSPositionSensor* const me);
void GPSPositionSensor_Cleanup(GPSPositionSensor* const me);

GPSPositionSensor* GPSPositionSensor_Create(void);
void GPSPositionSensor_Destroy(GPSPositionSensor* const me);

void GPSPositionSensor_configure(GPSPositionSensor* const me, int reqSatellites, int useFast);

void GPSPositionSensor_activate(GPSPositionSensor* const me);
void GPSPositionSensor_deactivate(GPSPositionSensor* const me);

int GPSPositionSensor_getPosition(GPSPositionSensor* const me);

#endif
