#include "TSREventQueue.h"
#include "Mutex.h"

static void cleanUpRelations(TSREventQueue* const me);

void TSREventQueue_Init(TSREventQueue* const me) {
    me->head = 0;
    me->size = 0;
    me->tail = 0;
    me->itsMutex = NULL;
}

void TSREventQueue_Cleanup(TSREventQueue* const me) {
    cleanUpRelations(me);
}

void TSREventQueue_isEmpty(TSREventQueue* const me) {
    return me->size <= 0;
}

int TSREventQueue_isFull(TSREventQueue* const me) {
    return me->size >= QSIZE-1;
}

    /* post enqueues an event and signals that fact */
int TSREventQueue_post(TSREventQueue* const me, Event e) {
    Mutex_lock(me->itsMutex);
    if (!TSREventQueue_isFull(me)) {
        me->q[me->head] = e;
        me->head = (me->head + 1) % QSIZE;
        me->size += 1;
        Mutex_release(me->itsMutex);
        postSignal(); /* signal that an event is present */
        return 1;
    }
    else {
        Mutex_release(me->itsMutex);
        return 0;
        };
}

/* pulls removes the oldest event from the queue */
/* pull should only be called when there is an event waiting */
Event TSREventQueue_pull(TSREventQueue* const me) {
    Event e;
    Mutex_lock(me->itsMutex);
    if (!TSREventQueue_isEmpty(me)) {
        e = me->q[me->tail];
        me->tail = (me->tail + 1) % QSIZE
        me->size -= 1;
    };
    Mutex_release(me->itsMutex);
    return e;
}

struct Mutex* TSREventQueue_getItsMutex(const TSREventQueue* const me) {
    return (struct Mutex*)me->itsMutex;
}

void TSREventQueue_setItsMutex(TSREventQueue* const me, struct Mutex* p_Mutex) {
    me->itsMutex = p_Mutex;
}

TSREventQueue * TSREventQueue_Create(void) {
    TSREventQueue* me = (TSREventQueue *) malloc(sizeof(TSREventQueue));
    if(me!=NULL)
            TSREventQueue_Init(me);
    return me;
}

void TSREventQueue_Destroy(TSREventQueue* const me) {
    if(me!=NULL)
            TSREventQueue_Cleanup(me);
    free(me);
}

static void cleanUpRelations(TSREventQueue* const me) {
    if(me->itsMutex != NULL)
            me->itsMutex = NULL;
}
