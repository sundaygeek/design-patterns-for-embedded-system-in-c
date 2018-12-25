#ifndef SmartInt_H
#define SmartInt_H

#include "SmartDataExample.h"
struct AlarmManager;

typedef struct SmartInt SmartInt;
struct SmartInt {
    ErrorCodeType errorCode;
    int highRange;
    int lowRange;
    int value;
    struct AlarmManager* itsAlarmManager;
};

/* Constructors and destructors:*/
void SmartInt_Init(SmartInt* const me, int val, int low, int high, struct AlarmManager* errMgr);

void SmartInt_Cleanup(SmartInt* const me);

/* Operations */
ErrorCodeType SmartInt_checkValidity(SmartInt* const me);

int SmartInt_cmp(SmartInt* const me, SmartInt s);

void SmartInt_errorHandler(SmartInt* const me, ErrorCodeType err);

ErrorCodeType SmartInt_getErrorCode(SmartInt* const me);

int SmartInt_getHighBoundary(SmartInt* const me);

int SmartInt_getLowBoundary(SmartInt* const me);

int SmartInt_getPrimitive(SmartInt* const me);

SmartInt SmartInt_getValue(SmartInt* const me);

int SmartInt_pCmp(SmartInt* const me, SmartInt s);

void SmartInt_setHighBoundary(SmartInt* const me, int high);

void SmartInt_setLowBoundary(SmartInt* const me, int low);

ErrorCodeType SmartInt_setPrimitive(SmartInt* const me, int p);

ErrorCodeType SmartInt_setValue(SmartInt* const me, SmartInt s);

struct AlarmManager* SmartInt_getItsAlarmManager(const SmartInt* const me);

void SmartInt_setItsAlarmManager(SmartInt* const me, struct AlarmManager* p_AlarmManager);

SmartInt * SmartInt_Create(int val, int low, int high, struct AlarmManager* errMgr);

void SmartInt_Destroy(SmartInt* const me);
#endif
