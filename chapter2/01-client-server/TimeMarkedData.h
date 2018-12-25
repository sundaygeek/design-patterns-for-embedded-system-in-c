#ifndef TimeMarkedData_H
#define TimeMarkedData_H

#include "ECGPkg.h"

typedef struct TimeMarkedData TimeMarkedData;
struct TimeMarkedData
{
    int timeInterval;
    int dataValue;
    struct TMDQueue* itsTMDQueue;
};

void TimeMarkedData_Init(TimeMarkedData* const me);
void TimeMarkedData_Cleanup(TimeMarkedData* const me);

void TimeMarkedData_setItsTMDQueue(TimeMarkedData* const me, struct TMDQueue* p_TMDQueue);

#endif //TimeMarkedData_H
