#include "KinematicData.h"

void KinematicData_Init(KinematicData* const me) {

    Attitude_Init(&(me->attitude));
    Position_Init(&(me->position));
    me->sema = OS_create_semaphore();
}

void KinematicData_Cleanup(KinematicData* const me) {
    OS_destroy_semaphore(me->sema);
}

struct Position KinematicData_getPosition(KinematicData* const me) {
    Position p;

    /* engage the lock */
    OS_lock_semaphore(me->sema);

    p = me->position;

    /* release the lock */
    OS_release_semaphore(me->sema);

    return p;
}

void KinematicData_setAttitude(KinematicData* const me, Attitude a) {
    /* engage the lock */
    OS_lock_semaphore(me->sema);

    me->attitude = a;

    /* release the lock */
    OS_release_semaphore(me->sema);
}

void KinematicData_setPosition(KinematicData* const me, Position p) {
    /* engage the lock */
    OS_lock_semaphore(me->sema);

    me->position = p;

    /* release the lock */
    OS_release_semaphore(me->sema);

    /*#]*/
}

KinematicData * KinematicData_Create(void) {
    KinematicData* me = (KinematicData *) malloc(sizeof(KinematicData));
    if(me!=NULL) {
        KinematicData_Init(me);
    }
    return me;
}

void KinematicData_Destroy(KinematicData* const me) {
    if(me!=NULL) {
        KinematicData_Cleanup(me);
    }
    free(me);
}

Attitude KinematicData_getAttitude(KinematicData* const me) {
    Attitude a;

    /* engage the lock */
    OS_lock_semaphore(me->sema);

    a = me->attitude;

    /* release the lock */
    OS_release_semaphore(me->sema);

    return a;
}
