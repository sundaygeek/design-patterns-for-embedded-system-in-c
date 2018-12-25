#include "SmartColor.h"
#include "AlarmManager.h"
static void cleanUpRelations(SmartColor* const me);

void SmartColor_Init(SmartColor* const me, ColorType val, ColorType low, ColorType high, struct AlarmManager* errMgr) {
    me->errorCode = NO_ERRORS;
    me->itsAlarmManager = NULL;

    me->lowRange = low;
    me->highRange = high;
    me->value = val;
    me->itsAlarmManager = errMgr;
}

void SmartColor_Cleanup(SmartColor* const me) {
    cleanUpRelations(me);
}

ErrorCodeType SmartColor_checkValidity(SmartColor* const me) {
    if (me->value < me->lowRange)
        return BELOW_RANGE;
    else if (me->value > me->highRange)
        return ABOVE_RANGE;
    else
        return NO_ERRORS;
}

int SmartColor_cmp(SmartColor* const me, SmartColor s) {
    return memcmp(me, &s, sizeof(s));
}

void SmartColor_errorHandler(SmartColor* const me, ErrorCodeType err) {
    AlarmManager_addAlarm(me->itsAlarmManager, err);
}

ErrorCodeType SmartColor_getErrorCode(SmartColor* const me) {
    return me->errorCode;
}

ColorType SmartColor_getHighBoundary(SmartColor* const me) {
    return me->highRange;
}

ColorType SmartColor_getLowBoundary(SmartColor* const me) {
    return me->lowRange;
}

ColorType SmartColor_getPrimitive(SmartColor* const me) {
    return me->value;
}

SmartColor SmartColor_getValue(SmartColor* const me) {
    return *me;
}

int SmartColor_pCmp(SmartColor* const me, SmartInt s) {
    ColorType a = SmartInt_getPrimitive(&s);
    return memcmp(&me->value, &a, sizeof(me->value));
}

void SmartColor_setHighBoundary(SmartColor* const me, ColorType high) {
    me->highRange = high;
}

void SmartColor_setLowBoundary(SmartColor* const me, ColorType low) {
    me->lowRange = low;
}

ErrorCodeType SmartColor_setPrimitive(SmartColor* const me, ColorType p) {
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

ErrorCodeType SmartColor_setValue(SmartColor* const me, SmartColor s) {
    me->errorCode = SmartColor_checkValidity(&s);
    if (me->errorCode == NO_ERRORS)
        *me = s;
    else
        SmartColor_errorHandler(me, me->errorCode);
    return me->errorCode;
}

struct AlarmManager* SmartColor_getItsAlarmManager(const SmartColor* const me) {
    return (struct AlarmManager*)me->itsAlarmManager;
}

void SmartColor_setItsAlarmManager(SmartColor* const me, struct AlarmManager* p_AlarmManager) {
    me->itsAlarmManager = p_AlarmManager;
}

SmartColor * SmartColor_Create(ColorType val, ColorType low, ColorType high, struct AlarmManager* errMgr) {
    SmartColor* me = (SmartColor *) malloc(sizeof(SmartColor));
    if(me!=NULL)
        SmartColor_Init(me, val, low, high, errMgr);
    return me;
}

void SmartColor_Destroy(SmartColor* const me) {
    if(me!=NULL)
        SmartColor_Cleanup(me);
    free(me);
}

static void cleanUpRelations(SmartColor* const me) {
    if(me->itsAlarmManager != NULL)
        me->itsAlarmManager = NULL;
}
