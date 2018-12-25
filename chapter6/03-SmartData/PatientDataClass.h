#ifndef PatientDataClass_H
#define PatientDataClass_H

#include "SmartDataExample.h"
#include "AlarmManager.h"
#include "SmartColor.h"
#include "SmartInt.h"

typedef struct PatientDataClass PatientDataClass;
struct PatientDataClass {
    SmartInt age;
    SmartColor backgroundColor;
    SmartColor foregroundColor;
    SmartInt heartRate;
    char name[100];
    long patientID;
    SmartInt weight;
};

/* Constructors and destructors:*/
void PatientDataClass_Init(PatientDataClass* const me, AlarmManager* errMgr);
void PatientDataClass_Cleanup(PatientDataClass* const me);

/* Operations */
ErrorCodeType PatientDataClass_checkAllData(PatientDataClass* const me);

int PatientDataClass_getAge(PatientDataClass* const me);
ColorType PatientDataClass_getBColor(PatientDataClass* const me);
ColorType PatientDataClass_getFColor(PatientDataClass* const me);
int PatientDataClass_getHeartRate(PatientDataClass* const me);
char* PatientDataClass_getName(PatientDataClass* const me);
int PatientDataClass_getWeight(PatientDataClass* const me);

void PatientDataClass_setAge(PatientDataClass* const me, int a);
void PatientDataClass_setBColor(PatientDataClass* const me, ColorType bc);
void PatientDataClass_setFColor(PatientDataClass* const me, ColorType fc);
void PatientDataClass_setHeartRate(PatientDataClass* const me, int hr);
void PatientDataClass_setName(PatientDataClass* const me, char* n);
void PatientDataClass_setWeight(PatientDataClass* const me, int w);

PatientDataClass * PatientDataClass_Create(AlarmManager* errMgr);
void PatientDataClass_Destroy(PatientDataClass* const me);
#endif
