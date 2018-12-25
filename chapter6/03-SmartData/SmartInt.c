#include "SmartInt.h"
#include "AlarmManager.h"

static void cleanUpRelations(SmartInt* const me);

void SmartInt_Init(SmartInt* const me, int val, int low, int high, struct AlarmManager* errMgr) {
    me->errorCode = NO_ERRORS;
    me->itsAlarmManager = NULL;

    me->lowRange = low;
    me->highRange = high;
    me->value = val;
    me->itsAlarmManager = errMgr;
}

void SmartInt_Cleanup(SmartInt* const me) {
    cleanUpRelations(me);
}

ErrorCodeType SmartInt_checkValidity(SmartInt* const me) {
    if (me->value < me->lowRange)
        return BELOW_RANGE;
    else if (me->value > me->highRange)
        return ABOVE_RANGE;
    else
        return NO_ERRORS;
}

int SmartInt_cmp(SmartInt* const me, SmartInt s) {
    return memcmp(me, &s, sizeof(s));
}

void SmartInt_errorHandler(SmartInt* const me, ErrorCodeType err) {
    AlarmManager_addAlarm(me->itsAlarmManager, err);
}

ErrorCodeType SmartInt_getErrorCode(SmartInt* const me) {
    return me->errorCode;
}

int SmartInt_getHighBoundary(SmartInt* const me) {
    return me->highRange;
}

int SmartInt_getLowBoundary(SmartInt* const me) {
    return me->lowRange;
}

int SmartInt_getPrimitive(SmartInt* const me) {
    return me->value;
}

SmartInt SmartInt_getValue(SmartInt* const me) {
    /*#[ operation getValue() */
    return *me;
    /*#]*/
}

int SmartInt_pCmp(SmartInt* const me, SmartInt s) {
    int a = SmartInt_getPrimitive(&s);
    return memcmp(&me->value, &a, sizeof(me->value));
}

void SmartInt_setHighBoundary(SmartInt* const me, int high) {
    me->highRange = high;
}

void SmartInt_setLowBoundary(SmartInt* const me, int low) {
    me->lowRange = low;
}

ErrorCodeType SmartInt_setPrimitive(SmartInt* const me, int p) {
    me->errorCode = NO_ERRORS;
    if (p < me->lowRange) {
        me->errorCode = BELOW_RANGE;
        AlarmManager_addAlarm(me->itsAlarmManager, me->errorCode);
        }
    else if (p > me->highRange) {
        me->errorCode = ABOVE_RANGE;
        AlarmManager_addAlarm(me->itsAlarmManager, me->errorCode);
        }
    else
        me->value = p;

    return me->errorCode;
}

ErrorCodeType SmartInt_setValue(SmartInt* const me, SmartInt s) {
    me->errorCode = SmartInt_checkValidity(&s);
    if (me->errorCode == NO_ERRORS)
        *me = s;
    else
        SmartInt_errorHandler(me, me->errorCode);
    return me->errorCode;
}

struct AlarmManager* SmartInt_getItsAlarmManager(const SmartInt* const me) {
    return (struct AlarmManager*)me->itsAlarmManager;
}

void SmartInt_setItsAlarmManager(SmartInt* const me, struct AlarmManager* p_AlarmManager) {
    me->itsAlarmManager = p_AlarmManager;
}

SmartInt * SmartInt_Create(int val, int low, int high, struct AlarmManager* errMgr) {
    SmartInt* me = (SmartInt *) malloc(sizeof(SmartInt));
    if(me!=NULL)
        SmartInt_Init(me, val, low, high, errMgr);
    return me;
}

void SmartInt_Destroy(SmartInt* const me) {
    if(me!=NULL)
        SmartInt_Cleanup(me);
    free(me);
}

static void cleanUpRelations(SmartInt* const me) {
    if(me->itsAlarmManager != NULL)
        me->itsAlarmManager = NULL;
}
