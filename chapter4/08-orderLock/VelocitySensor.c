#include "VelocitySensor.h"
#include "Mutex.h"
#include "ResourceList.h"

static void cleanUpRelations(VelocitySensor* const me);

void VelocitySensor_Init(VelocitySensor* const me) {
    me->resourceID = 2;
    {
        Velocity_Init(&(me->velocity));
    }
    me->itsMutex = NULL;
    me->itsResourceList = NULL;
}

void VelocitySensor_Cleanup(VelocitySensor* const me) {
    cleanUpRelations(me);
}

struct Velocity VelocitySensor_getVelocity(VelocitySensor* const me) {
    return me->velocity;
}

int VelocitySensor_lockDyadic(VelocitySensor* const me) {
    int ok;

    Mutex_lock(me->itsMutex);
    ok = ResourceList_addLock(me->itsResourceList, me->resourceID);
    if (ok != 0)
        Mutex_release(me->itsMutex);
    return ok;
}

void VelocitySensor_releaseDyadic(VelocitySensor* const me) {
    ResourceList_removeLock(me->itsResourceList, me->resourceID);
    Mutex_release(me->itsMutex);
}

void VelocitySensor_setVelocity(VelocitySensor* const me, struct Velocity v) {
    me->velocity = v;
}

struct Mutex* VelocitySensor_getItsMutex(const VelocitySensor* const me) {
    return (struct Mutex*)me->itsMutex;
}

void VelocitySensor_setItsMutex(VelocitySensor* const me, struct Mutex* p_Mutex) {
    me->itsMutex = p_Mutex;
}

struct ResourceList* VelocitySensor_getItsResourceList(const VelocitySensor* const me) {
    return (struct ResourceList*)me->itsResourceList;
}

void VelocitySensor_setItsResourceList(VelocitySensor* const me, struct ResourceList* p_ResourceList) {
    me->itsResourceList = p_ResourceList;
}

VelocitySensor * VelocitySensor_Create(void) {
    VelocitySensor* me = (VelocitySensor *) malloc(sizeof(VelocitySensor));
    if(me!=NULL)
            VelocitySensor_Init(me);
    return me;
}

void VelocitySensor_Destroy(VelocitySensor* const me) {
    if(me!=NULL)
            VelocitySensor_Cleanup(me);
    free(me);
}

static void cleanUpRelations(VelocitySensor* const me) {
    if(me->itsMutex != NULL)
            me->itsMutex = NULL;
    if(me->itsResourceList != NULL)
            me->itsResourceList = NULL;
}
