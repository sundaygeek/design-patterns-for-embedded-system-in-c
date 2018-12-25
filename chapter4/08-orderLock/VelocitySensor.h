#ifndef VelocitySensor_H
#define VelocitySensor_H

/* brings in the error codes */
#include "OrderedLockingExample.h"
#include "Velocity.h"
struct Mutex;

struct ResourceList;

typedef struct VelocitySensor VelocitySensor;
struct VelocitySensor {
    int resourceID;
    struct Velocity velocity;
    struct Mutex* itsMutex;
    struct ResourceList* itsResourceList;
};

void VelocitySensor_Init(VelocitySensor* const me);

void VelocitySensor_Cleanup(VelocitySensor* const me);

/* Operations */
struct Velocity VelocitySensor_getVelocity(VelocitySensor* const me);

int VelocitySensor_lockDyadic(VelocitySensor* const me);

void VelocitySensor_releaseDyadic(VelocitySensor* const me);

void VelocitySensor_setVelocity(VelocitySensor* const me, struct Velocity v);

struct Mutex* VelocitySensor_getItsMutex(const VelocitySensor* const me);

void VelocitySensor_setItsMutex(VelocitySensor* const me, struct Mutex* p_Mutex);

struct ResourceList* VelocitySensor_getItsResourceList(const VelocitySensor* const me);

void VelocitySensor_setItsResourceList(VelocitySensor* const me, struct ResourceList* p_ResourceList);

VelocitySensor * VelocitySensor_Create(void);

void VelocitySensor_Destroy(VelocitySensor* const me);

#endif
