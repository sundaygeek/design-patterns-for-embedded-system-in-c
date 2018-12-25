#ifndef KinematicData_H
#define KinematicData_H

#include "GuardedCallExample.h"
#include "Attitude.h"
#include "OSSemaphore.h"
#include "Position.h"

typedef struct KinematicData KinematicData;
struct KinematicData {
    struct Attitude attitude;
    struct Position position;
    OSSemaphore* sema;      /*## mutex semaphore */
};

/* Constructors and destructors:*/
void KinematicData_Init(KinematicData* const me);
void KinematicData_Cleanup(KinematicData* const me);

/* Operations */

Attitude KinematicData_getAttitude(KinematicData* const me);
struct Position KinematicData_getPosition(KinematicData* const me);

void KinematicData_setAttitude(KinematicData* const me, Attitude a);

void KinematicData_setPosition(KinematicData* const me, Position p);

KinematicData * KinematicData_Create(void);

void KinematicData_Destroy(KinematicData* const me);

#endif
