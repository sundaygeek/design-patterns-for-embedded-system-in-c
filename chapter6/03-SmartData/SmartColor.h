#ifndef SmartColor_H
#define SmartColor_H

#include "SmartDataExample.h"
#include "SmartInt.h"

struct AlarmManager;

typedef struct SmartColor SmartColor;
struct SmartColor {
    ErrorCodeType errorCode;
    ColorType highRange;
    ColorType lowRange;
    ColorType value;
    struct AlarmManager* itsAlarmManager;
};
/* Constructors and destructors:*/

void SmartColor_Init(SmartColor* const me, ColorType val, ColorType low, ColorType high, struct AlarmManager* errMgr);
void SmartColor_Cleanup(SmartColor* const me);

/* Operations */
ErrorCodeType SmartColor_checkValidity(SmartColor* const me);
int SmartColor_cmp(SmartColor* const me, SmartColor s);
void SmartColor_errorHandler(SmartColor* const me, ErrorCodeType err);
int SmartColor_pCmp(SmartColor* const me, SmartInt s);


ErrorCodeType SmartColor_getErrorCode(SmartColor* const me);
ColorType SmartColor_getHighBoundary(SmartColor* const me);
ColorType SmartColor_getLowBoundary(SmartColor* const me);
ColorType SmartColor_getPrimitive(SmartColor* const me);
SmartColor SmartColor_getValue(SmartColor* const me);

void SmartColor_setHighBoundary(SmartColor* const me, ColorType high);
void SmartColor_setLowBoundary(SmartColor* const me, ColorType low);
ErrorCodeType SmartColor_setPrimitive(SmartColor* const me, ColorType p);
ErrorCodeType SmartColor_setValue(SmartColor* const me, SmartColor s);

struct AlarmManager* SmartColor_getItsAlarmManager(const SmartColor* const me);
void SmartColor_setItsAlarmManager(SmartColor* const me, struct AlarmManager* p_AlarmManager);

SmartColor * SmartColor_Create(ColorType val, ColorType low, ColorType high, struct AlarmManager* errMgr);
void SmartColor_Destroy(SmartColor* const me);
#endif
