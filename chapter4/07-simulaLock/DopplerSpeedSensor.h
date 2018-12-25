#ifndef DopplerSpeedSensor_H
#define DopplerSpeedSensor_H

typedef struct DopplerSpeedSensor DopplerSpeedSensor;
struct DopplerSpeedSensor
{
    int sampleRate;
    int state;
    int speed;
};

void DopplerSpeedSensor_Init(DopplerSpeedSensor* const me);
void DopplerSpeedSensor_Cleanup(DopplerSpeedSensor* const me);
DopplerSpeedSensor* DopplerSpeedSensor_Create(void);
void DopplerSpeedSensor_Destroy(DopplerSpeedSensor* const me);

void DopplerSpeedSensor_configure(DopplerSpeedSensor* const me, int sampleRate);

int DopplerSpeedSensor_getSpeed(DopplerSpeedSensor* const me);

void DopplerSpeedSensor_enable(DopplerSpeedSensor* const me);
void DopplerSpeedSensor_disable(DopplerSpeedSensor* const me);

#endif
