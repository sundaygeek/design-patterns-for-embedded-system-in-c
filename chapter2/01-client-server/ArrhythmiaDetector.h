#ifndef ArrhythmiaDetector_H
#define ArrhythmiaDetector_H

#include "ECGPkg.h"

struct TMDQueue;

typedef struct ArrhythmiaDetector ArrhythmiaDetector;
struct ArrhythmiaDetector
{
    int pcvCount;
    int STSegmentHeight;
    int firstDegreeHeatBlock;
    int Two_one_heartBlock;
    int prematureAtrialContraction;
    int flbrillation;
    int index;
    struct TMDQueue* itsTMDQueue;
};

// constructions and desctructions
void ArrhythmiaDetector_Init(ArrhythmiaDetector* const me);
void ArrhythmiaDetector_Cleanup(ArrhythmiaDetector* const me);

void ArrhythmiaDetector_indentifyArrhythmia(ArrhythmiaDetector* const me);
void ArrhythmiaDetector_getDataSample(ArrhythmiaDetector* const me);
void ArrhythmiaDetector_setItsTMDQueue(ArrhythmiaDetector* const me, struct TMDQueue* p_TMDQueue);

ArrhythmiaDetector * ArrhythmiaDetector_Create(void);
ArrhythmiaDetector * ArrhythmiaDetector_Destroy(ArrhythmiaDetector* const me);

#endif //ArrhythmiaDetector_H
