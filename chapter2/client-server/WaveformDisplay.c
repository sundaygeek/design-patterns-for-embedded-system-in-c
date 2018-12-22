#include "WaveformDisplay.h"
#include "TMDQueue.h"

void WaveformDisplay_Init(WaveformDisplay* const me){

}

void WaveformDisplay_Cleanup(WaveformDisplay* const me){

}

void WaveformDisplay_getScalarValue(WaveformDisplay* const me){
    TimeMarkedData tmd;
    tmd = TMDQueue_remove(me->itsTMDQueue, me->index);
    printf("WaveformDisplay index: %d TimeInterval: %d  DataValue: %d\n", me->index, tmd.timeInterval, tmd.dataValue);
    me->index = TMDQueue_getNextIndex(me->itsTMDQueue, me->index);
}

void WaveformDisplay_setItsTMDQueue(WaveformDisplay* const me, struct TMDQueue* p_TMDQueue){
    me->itsTMDQueue = p_TMDQueue;
}

WaveformDisplay* WaveformDisplay_Create(void){

}

WaveformDisplay* WaveformDisplay_Destroy(WaveformDisplay* const me){

}
