#include "PatientDataClass.h"
void PatientDataClass_Init(PatientDataClass* const me, AlarmManager* errMgr) {
    strcpy(me->name, "         ");
    me->patientID = 0;
    /* initialize smart variables */
    SmartInt_Init(&me->weight, 0, 0, 500, errMgr);
    SmartInt_Init(&me->age, 0, 0, 130, errMgr);
    SmartInt_Init(&me->heartRate, 0, 0, 400, errMgr);
    SmartColor_Init(&me->foregroundColor, WHITE, BLACK, WHITE, errMgr);
    SmartColor_Init(&me->backgroundColor, BLACK, BLACK, WHITE, errMgr);
}

void PatientDataClass_Cleanup(PatientDataClass* const me) {
}

ErrorCodeType PatientDataClass_checkAllData(PatientDataClass* const me) {
    ErrorCodeType res;
    res = SmartInt_checkValidity(&me->weight);
    if (res != NO_ERRORS)
        return res;
    res = SmartInt_checkValidity(&me->age);
    if (res != NO_ERRORS)
        return res;
    res = SmartInt_checkValidity(&me->heartRate);
    if (res != NO_ERRORS)
        return res;
    res = SmartColor_checkValidity(&me->foregroundColor);
    if (res != NO_ERRORS)
        return res;
    res = SmartColor_checkValidity(&me->backgroundColor);
    if (res != NO_ERRORS)
        return res;
}

int PatientDataClass_getAge(PatientDataClass* const me) {
    return SmartInt_getPrimitive(&me->age);
}

ColorType PatientDataClass_getBColor(PatientDataClass* const me) {
    return SmartColor_getPrimitive(&me->backgroundColor);
}

ColorType PatientDataClass_getFColor(PatientDataClass* const me) {
    return SmartColor_getPrimitive(&me->foregroundColor);
}

int PatientDataClass_getHeartRate(PatientDataClass* const me) {
    return SmartInt_getPrimitive(&me->heartRate);
}

char* PatientDataClass_getName(PatientDataClass* const me) {
    return me->name;
}

int PatientDataClass_getWeight(PatientDataClass* const me) {
    return SmartInt_getPrimitive(&me->weight);
}

void PatientDataClass_setAge(PatientDataClass* const me, int a) {
    SmartInt_setPrimitive(&me->age, a);
}

void PatientDataClass_setBColor(PatientDataClass* const me, ColorType bc) {
    SmartColor_setPrimitive(&me->backgroundColor, bc);
}

void PatientDataClass_setFColor(PatientDataClass* const me, ColorType fc) {
    SmartColor_setPrimitive(&me->foregroundColor, fc);
}

void PatientDataClass_setHeartRate(PatientDataClass* const me, int hr) {
    SmartInt_setPrimitive(&me->heartRate, hr);
}

void PatientDataClass_setName(PatientDataClass* const me, char* n) {
    strcpy(me->name, n);
}

void PatientDataClass_setWeight(PatientDataClass* const me, int w) {
    SmartInt_setPrimitive(&me->weight, w);
}

PatientDataClass * PatientDataClass_Create(AlarmManager* errMgr) {
    PatientDataClass* me = (PatientDataClass *) malloc(sizeof(PatientDataClass));
    if(me!=NULL)
        PatientDataClass_Init(me, errMgr);
    return me;
}

void PatientDataClass_Destroy(PatientDataClass* const me) {
    if(me!=NULL)
        PatientDataClass_Cleanup(me);
    free(me);
}
