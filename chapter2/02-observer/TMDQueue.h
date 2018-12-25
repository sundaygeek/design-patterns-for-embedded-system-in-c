#ifndef TMDQueue_H
#define TMDQueue_H

/*## auto_generated */
#include <stdio.h>
#include "ECGPkg.h"
#include "TimeMarkedData.h"

struct NotificationHandle;

typedef struct TMDQueue TMDQueue;
/*
 This queue is meant to operate as a "leaky" queue. In this queue,
 data is never removed per se, but is instead overwritten when the
 buffer pointer wraps around. This allows for many clients to read
 the same data from the queue. */
struct TMDQueue {
    int head;
    int nSubscribers;
    int size;
    struct TimeMarkedData buffer[QUEUE_SIZE];
    struct NotificationHandle* itsNotificationHandle;
};

void (*UpdateFuncPtr)(HistogramDisplay* const me, const struct TimeMarkedData tmd);

/* Constructors and destructors:*/
void TMDQueue_Init(TMDQueue* const me);
void TMDQueue_Cleanup(TMDQueue* const me);

/* Operations */
int TMDQueue_getNextIndex(TMDQueue* const me, int index);
void TMDQueue_insert(TMDQueue* const me, const struct TimeMarkedData tmd);
boolean TMDQueue_isEmpty(TMDQueue* const me);
void TMDQueue_notify(TMDQueue* const me, const struct TimeMarkedData tmd);
struct TimeMarkedData TMDQueue_remove(TMDQueue* const me, int index);

/* The NotificationHandle is managed as a linked list, with insertions coming at the end.  */
void TMDQueue_subscribe(TMDQueue* const me, const UpdateFuncPtr updateFuncAddr);
int TMDQueue_unsubscribe(TMDQueue* const me, const UpdateFuncPtr updateFuncAddr);

int TMDQueue_getBuffer(const TMDQueue* const me);

struct NotificationHandle* TMDQueue_getItsNotificationHandle(const TMDQueue* const me);
void TMDQueue_setItsNotificationHandle(TMDQueue* const me, struct NotificationHandle* p_NotificationHandle);

TMDQueue * TMDQueue_Create(void);
void TMDQueue_Destroy(TMDQueue* const me);

#endif
