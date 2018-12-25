#include "PatientData.h"
#include "AlarmManager.h"
#include <string.h>
#include <stdio.h>

static void cleanUpRelations(PatientData* const me);

void PatientData_Init(PatientData* const me) {
    me->itsAlarmManager = NULL;
    strcpy(me->pData.name, " ");
    me->pData.patientID = 0;
    me->pData.weight = 0;
    me->pData.age = 0;
    me->pData.gender = HERMAPHRODITE;
    me->pData.systolicBP = 0;
    me->pData.diastolicBP = 0;
    me->pData.temperature = 0;
    me->pData.heartRate = 0;
    me->pData.bloodO2Conc = 0;
    me->crc = computeCRC((unsigned char *)&me->pData, sizeof(me->pData), 0xffff, 0);
}

void PatientData_Cleanup(PatientData* const me) {
    cleanUpRelations(me);
}

int PatientData_checkData(PatientData* const me) {
    unsigned short result = computeCRC((unsigned char *)&me->pData, sizeof(me->pData), 0xffff, 0);
    printf("computed CRC = %d, stored CRC = %d\n", result, me->crc);
    return result == me->crc;

}

void PatientData_errorHandler(PatientData* const me, ErrorCodeType errCode) {
    AlarmManager_addAlarm(me->itsAlarmManager, errCode);
}

unsigned short PatientData_getAge(PatientData* const me) {
    if (PatientData_checkData(me))
        return me->pData.age;
    else {
        PatientData_errorHandler(me, CORRUPT_DATA);
        return 0;
        };
}

unsigned short PatientData_getBloodO2Conc(PatientData* const me) {
    if (PatientData_checkData(me))
        return me->pData.bloodO2Conc;
    else {
        PatientData_errorHandler(me, CORRUPT_DATA);
        return 0;
        };
}

unsigned short PatientData_getDiastolicBP(PatientData* const me) {
    if (PatientData_checkData(me))
        return me->pData.diastolicBP;
    else {
        PatientData_errorHandler(me, CORRUPT_DATA);
        return 0;
        };
}

GenderType PatientData_getGender(PatientData* const me) {
    if (PatientData_checkData(me))
        return me->pData.gender;
    else {
        PatientData_errorHandler(me, CORRUPT_DATA);
        return 0;
        };
}

char* PatientData_getName(PatientData* const me) {
    if (PatientData_checkData(me))
        return me->pData.name;
    else {
        PatientData_errorHandler(me, CORRUPT_DATA);
        return 0;
        };
}

unsigned long PatientData_getPatientID(PatientData* const me) {
    if (PatientData_checkData(me))
        return me->pData.patientID;
    else {
        PatientData_errorHandler(me, CORRUPT_DATA);
        return 0;
        };
}

unsigned short PatientData_getSystolicBP(PatientData* const me) {
    if (PatientData_checkData(me))
        return me->pData.systolicBP;
    else {
        PatientData_errorHandler(me, CORRUPT_DATA);
        return 0;
        };
}

unsigned short PatientData_getTemperature(PatientData* const me) {
    if (PatientData_checkData(me))
        return me->pData.temperature;
    else {
        PatientData_errorHandler(me, CORRUPT_DATA);
        return 0;
        };
}

double PatientData_getWeight(PatientData* const me) {
    if (PatientData_checkData(me))
        return me->pData.weight;
    else {
        PatientData_errorHandler(me, CORRUPT_DATA);
        return 0;
        };
}

void PatientData_setAge(PatientData* const me, unsigned short a) {
    if (PatientData_checkData(me)) {
        me->pData.age = a;
        me->crc = computeCRC((unsigned char *)&me->pData, sizeof(me->pData), 0xffff, 0);
        if (!PatientData_checkData(me))
            PatientData_errorHandler(me, CORRUPT_DATA);
        }
    else  {
        printf("Set failed\n");
        PatientData_errorHandler(me, CORRUPT_DATA);
        };
}

void PatientData_setBloodO2Conc(PatientData* const me, unsigned short o2) {
    if (PatientData_checkData(me)) {
        me->pData.bloodO2Conc = o2;
        me->crc = computeCRC((unsigned char *)&me->pData, sizeof(me->pData), 0xffff, 0);
        if (!PatientData_checkData(me))
            PatientData_errorHandler(me, CORRUPT_DATA);
        }
    else  {
        printf("Set failed\n");
        PatientData_errorHandler(me, CORRUPT_DATA);
        };
}

void PatientData_setDiastolicBP(PatientData* const me, unsigned short dBP) {
    if (PatientData_checkData(me)) {
        me->pData.diastolicBP = dBP;
        me->crc = computeCRC((unsigned char *)&me->pData, sizeof(me->pData), 0xffff, 0);
        if (!PatientData_checkData(me))
            PatientData_errorHandler(me, CORRUPT_DATA);
        }
    else  {
        printf("Set failed\n");
        PatientData_errorHandler(me, CORRUPT_DATA);
        };
}

void PatientData_setGender(PatientData* const me, GenderType g) {
    if (PatientData_checkData(me)) {
        me->pData.gender = g;
        me->crc = computeCRC((unsigned char *)&me->pData, sizeof(me->pData), 0xffff, 0);
        if (!PatientData_checkData(me))
            PatientData_errorHandler(me, CORRUPT_DATA);
        }
    else  {
        printf("Set failed\n");
        PatientData_errorHandler(me, CORRUPT_DATA);
        };
}

void PatientData_setName(PatientData* const me, char* n) {
    if (PatientData_checkData(me)) {
        strcpy(me->pData.name, n);
        me->crc = computeCRC((unsigned char *)&me->pData, sizeof(me->pData), 0xffff, 0);
        if (!PatientData_checkData(me))
            PatientData_errorHandler(me, CORRUPT_DATA);
        }
    else  {
        printf("Set failed\n");
        PatientData_errorHandler(me, CORRUPT_DATA);
        };
}

void PatientData_setPatientID(PatientData* const me, unsigned long id) {
    if (PatientData_checkData(me)) {
        me->pData.patientID = id;
        me->crc = computeCRC((unsigned char *)&me->pData, sizeof(me->pData), 0xffff, 0);
        if (!PatientData_checkData(me))
            PatientData_errorHandler(me, CORRUPT_DATA);
        }
    else  {
        printf("Set failed\n");
        PatientData_errorHandler(me, CORRUPT_DATA);
        };
}

void PatientData_setSystolicBP(PatientData* const me, unsigned short sBP) {
    if (PatientData_checkData(me)) {
        me->pData.systolicBP = sBP;
        me->crc = computeCRC((unsigned char *)&me->pData, sizeof(me->pData), 0xffff, 0);
        if (!PatientData_checkData(me))
            PatientData_errorHandler(me, CORRUPT_DATA);
        }
    else  {
        printf("Set failed\n");
        PatientData_errorHandler(me, CORRUPT_DATA);
        };
}

void PatientData_setTemperature(PatientData* const me, unsigned short t) {
    if (PatientData_checkData(me)) {
        me->pData.temperature = t;
        me->crc = computeCRC((unsigned char *)&me->pData, sizeof(me->pData), 0xffff, 0);
        if (!PatientData_checkData(me))
            PatientData_errorHandler(me, CORRUPT_DATA);
        }
    else  {
        printf("Set failed\n");
        PatientData_errorHandler(me, CORRUPT_DATA);
        };
}

void PatientData_setWeight(PatientData* const me, double w) {
    if (PatientData_checkData(me)) {
        me->pData.weight = w;
        me->crc = computeCRC((unsigned char *)&me->pData, sizeof(me->pData), 0xffff, 0);
        if (!PatientData_checkData(me))
            PatientData_errorHandler(me, CORRUPT_DATA);
        }
    else  {
        printf("Set failed\n");
        PatientData_errorHandler(me, CORRUPT_DATA);
        };
}

struct AlarmManager* PatientData_getItsAlarmManager(const PatientData* const me) {
    return (struct AlarmManager*)me->itsAlarmManager;
}

void PatientData_setItsAlarmManager(PatientData* const me, struct AlarmManager* p_AlarmManager) {
    me->itsAlarmManager = p_AlarmManager;
}

PatientData * PatientData_Create(void) {
    PatientData* me = (PatientData *) malloc(sizeof(PatientData));
    if(me!=NULL)
        PatientData_Init(me);
    return me;
}

void PatientData_Destroy(PatientData* const me) {
    if(me!=NULL)
        PatientData_Cleanup(me);
    free(me);
}

static void cleanUpRelations(PatientData* const me) {
    if(me->itsAlarmManager != NULL)
        me->itsAlarmManager = NULL;
}
