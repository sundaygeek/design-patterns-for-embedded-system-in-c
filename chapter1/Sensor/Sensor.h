#ifndef Sensor_H
#define Sensor_H

#define WRITE_ADDR  0x1111
#define WRITE_MASK  0x2222
#define READ_ADDR   0x3333
#define SENSOR_PORT 0x4444

typedef enum _interfaceType
{
    MEMORY_MAPPED,
    PORT_MAPPED,
    MAPPED_MAX
} interfaceType;

// class sensor
typedef struct Sensor Sensor;
struct Sensor
{
    int filterFrequency;
    int updateFrequency;
    int value;
    int whatKindOfInterface;
};

int Sensor_getFilterFrequency(const Sensor* const me);
void Sensor_setFilterFrequency(Sensor* const me, int p_filterFrequency);

int Sensor_getUpdateFrequency(const Sensor* const me);
void Sensor_setUpdateFrequency(Sensor* const me, int p_updateFrequency);

int Sensor_getValue(const Sensor* const me);
int Sensor_acquireValue(Sensor* me);

Sensor* Sensor_Create(void);
void Sensor_Destroy(Sensor* const me);

#endif //Sensor_H
