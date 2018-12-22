#include "ArrhythmiaDetector.h"
#include "TMDQueue.h"

void ArrhythmiaDetector_Init(ArrhythmiaDetector* const me){

}

void ArrhythmiaDetector_Cleanup(ArrhythmiaDetector* const me){

}

void ArrhythmiaDetector_indentifyArrhythmia(ArrhythmiaDetector* const me){

}

void ArrhythmiaDetector_getDataSample(ArrhythmiaDetector* const me){
    TimeMarkedData tmd;
    tmd = TMDQueue_remove(me->itsTMDQueue, me->index);
    printf("ArrhythmiaDetector index: %d TimeInterval: %d  DataValue: %d\n", me->index, tmd.timeInterval, tmd.dataValue);
    me->index = TMDQueue_getNextIndex(me->itsTMDQueue, me->index);
}

void ArrhythmiaDetector_setItsTMDQueue(ArrhythmiaDetector* const me, struct TMDQueue* p_TMDQueue){
    me->itsTMDQueue = p_TMDQueue;
}

ArrhythmiaDetector * ArrhythmiaDetector_Create(void){
    ArrhythmiaDetector* me = (ArrhythmiaDetector*)malloc(sizeof(ArrhythmiaDetector));
    if (me != NULL)
    {
        ArrhythmiaDetector_Init(me);
    }
    return me;
}

ArrhythmiaDetector * ArrhythmiaDetector_Destroy(ArrhythmiaDetector* const me){
    if (me != NULL)
    {
        ArrhythmiaDetector_Cleanup(me);
    }
    free(me);
}
