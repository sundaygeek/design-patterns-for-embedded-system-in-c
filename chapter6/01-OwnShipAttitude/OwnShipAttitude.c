#include "OwnShipAttitude.h"
#include "AlarmManager.h"

static void cleanUpRelations(OwnShipAttitude* const me);

void OwnShipAttitude_Init(OwnShipAttitude* const me) {
    AttitudeDataType_Init(&(me->attitude));
    AttitudeDataType_Init(&(me->invertedAttitude));
    me->itsAlarmManager = NULL;
}

void OwnShipAttitude_Cleanup(OwnShipAttitude* const me) {
    cleanUpRelations(me);
}

void OwnShipAttitude_errorHandler(OwnShipAttitude* const me) {
    AlarmManager_addAlarm(me->itsAlarmManager, ATTITUDE_MEMORY_FAULT);
}

int OwnShipAttitude_getAttitude(OwnShipAttitude* const me, AttitudeDataType * aPtr) {
    AttitudeDataType ia = OwnShipAttitude_invert(me, me->invertedAttitude);

    if (me->attitude.roll == ia.roll && me->attitude.yaw == ia.yaw &&
        me->attitude.pitch == ia.pitch ) {
        *aPtr = me->attitude;
        return 1;
        }
    else  {
        OwnShipAttitude_errorHandler(me);
        return 0;
        };
}

AttitudeDataType OwnShipAttitude_invert(OwnShipAttitude* const me, AttitudeDataType a) {
    a.roll = ~a.roll;
    a.yaw = ~a.yaw;
    a.pitch = ~a.pitch;
    return a;
}

void OwnShipAttitude_setAttitude(OwnShipAttitude* const me, AttitudeDataType a) {
    me->attitude = a;
    me->invertedAttitude = OwnShipAttitude_invert(me, a);
}

struct AlarmManager* OwnShipAttitude_getItsAlarmManager(const OwnShipAttitude* const me) {
    return (struct AlarmManager*)me->itsAlarmManager;
}

void OwnShipAttitude_setItsAlarmManager(OwnShipAttitude* const me, struct AlarmManager* p_AlarmManager) {
    me->itsAlarmManager = p_AlarmManager;
}

OwnShipAttitude * OwnShipAttitude_Create(void) {
    OwnShipAttitude* me = (OwnShipAttitude *) malloc(sizeof(OwnShipAttitude));
    if(me!=NULL)
        OwnShipAttitude_Init(me);
    return me;
}

void OwnShipAttitude_Destroy(OwnShipAttitude* const me) {
    if(me!=NULL)
        OwnShipAttitude_Cleanup(me);
    free(me);
}

static void cleanUpRelations(OwnShipAttitude* const me) {
    if(me->itsAlarmManager != NULL)
        me->itsAlarmManager = NULL;
}
