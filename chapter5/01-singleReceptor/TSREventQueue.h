#ifndef TSREventQueue_H
#define TSREventQueue_H

#include "TokenizerAsyncSinglePkg.h"

struct Mutex;

typedef struct TSREventQueue TSREventQueue;
struct TSREventQueue {
    Event q[100];
    int size;
    int head;
    int tail;
    struct Mutex* itsMutex;
};

/* Constructors and destructors:*/
void TSREventQueue_Init(TSREventQueue* const me);

void TSREventQueue_Cleanup(TSREventQueue* const me);

/* Operations */

    void TSREventQueue_isEmpty(TSREventQueue* const me);

int TSREventQueue_isFull(TSREventQueue* const me);

/* puts the passed event in */
/* the event queue and then */
/* calls the event receptor of */
/* the state machine. Note */
/* if the queue overflows an  */
/* error code (1) is returned.  */
int TSREventQueue_post(TSREventQueue* const me, Event e);

/* It is assumed that the caller has */
/* ensured that there is at least one */
/* event in the queue (via the isEmpty() */
/* funtion) prior to calling this function.  */
/* Othersize they get a default event.  */
Event TSREventQueue_pull(TSREventQueue* const me);

struct Mutex* TSREventQueue_getItsMutex(const TSREventQueue* const me);

void TSREventQueue_setItsMutex(TSREventQueue* const me, struct Mutex* p_Mutex);

TSREventQueue * TSREventQueue_Create(void);

void TSREventQueue_Destroy(TSREventQueue* const me);

#endif
