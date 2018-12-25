#ifndef PatientData_H
#define PatientData_H

#include "CRCExample.h"
struct AlarmManager;

typedef struct PatientData PatientData;
struct PatientData {
    PatientDataType pData;
    unsigned short crc;
    struct AlarmManager* itsAlarmManager;
};

void PatientData_Init(PatientData* const me);
void PatientData_Cleanup(PatientData* const me);

/* Operations */
void PatientData_errorHandler(PatientData* const me, ErrorCodeType errCode);

unsigned short PatientData_getAge(PatientData* const me);

unsigned short PatientData_getBloodO2Conc(PatientData* const me);

unsigned short PatientData_getDiastolicBP(PatientData* const me);

GenderType PatientData_getGender(PatientData* const me);

char* PatientData_getName(PatientData* const me);

unsigned long PatientData_getPatientID(PatientData* const me);

unsigned short PatientData_getSystolicBP(PatientData* const me);

unsigned short PatientData_getTemperature(PatientData* const me);

double PatientData_getWeight(PatientData* const me);

void PatientData_setAge(PatientData* const me, unsigned short a);

void PatientData_setBloodO2Conc(PatientData* const me, unsigned short o2);

void PatientData_setDiastolicBP(PatientData* const me, unsigned short dBP);

void PatientData_setGender(PatientData* const me, GenderType g);

void PatientData_setName(PatientData* const me, char* n);

void PatientData_setPatientID(PatientData* const me, unsigned long id);

void PatientData_setSystolicBP(PatientData* const me, unsigned short sBP);

void PatientData_setTemperature(PatientData* const me, unsigned short t);

void PatientData_setWeight(PatientData* const me, double w);

int PatientData_checkData(PatientData* const me);

struct AlarmManager* PatientData_getItsAlarmManager(const PatientData* const me);

void PatientData_setItsAlarmManager(PatientData* const me, struct AlarmManager* p_AlarmManager);

PatientData * PatientData_Create(void);

void PatientData_Destroy(PatientData* const me);
#endif
