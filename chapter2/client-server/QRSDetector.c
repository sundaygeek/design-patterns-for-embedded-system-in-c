#include "QRSDetector.h"
#include "TMDQueue.h"
#include <stdlib.h>

static void cleanUpRelations(QRSDetector* const me);

void QRSDetector_Init(QRSDetector* const me){
    me->heartRate = 0;
    me->index = 0;
    me->itsTMDQueue = NULL;
}

void QRSDetector_Cleanup(QRSDetector* const me){
    cleanUpRelations(me);
}

void QRSDetector_computeHR(QRSDetector* const me){
    me->heartRate = me->heartRate + 10;
}

void QRSDetector_getDataSample(QRSDetector* const me){
    TimeMarkedData tmd;
    tmd = TMDQueue_remove(me->itsTMDQueue, me->index);
    printf("QRSDetector index: %d TimeInterval: %d  DataValue: %d\n", me->index, tmd.timeInterval, tmd.dataValue);
    me->index = TMDQueue_getNextIndex(me->itsTMDQueue, me->index);
}

void QRSDetector_setItsTMDQueue(QRSDetector* const me, struct TMDQueue* p_TMDQueue){
    me->itsTMDQueue = p_TMDQueue;
}

struct TMDQueue* QRSDetector_getItsTMDQueue(const QRSDetector* const me){
    return (struct TMDQueue*)me->itsTMDQueue;
}

QRSDetector * QRSDetector_Create(void){
    QRSDetector* me = (QRSDetector*)malloc(sizeof(QRSDetector));
    if (me != NULL)
    {
        QRSDetector_Init(me);
    }
    return me;
}

QRSDetector * QRSDetector_Destroy(QRSDetector* const me){
    if (me != NULL)
    {
        QRSDetector_Cleanup(me);
    }
    free(me);
}

static void cleanUpRelations(QRSDetector* const me) {
    if(me->itsTMDQueue != NULL)
    {
        me->itsTMDQueue = NULL;
    }
}
