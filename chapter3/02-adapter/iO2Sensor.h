#ifndef IO2Sensor_H
#define IO2Sensor_H

typedef struct iO2Sensor iO2Sensor;
struct iO2Sensor
{
    int (*gimmeO2Flow)(void);
    int (*gimmeO2Conc)(void);
};

#endif // IO2Sensor_H
