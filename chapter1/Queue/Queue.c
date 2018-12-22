#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

void Queue_Init(Queue* const me,
                int (*isFullFunc)(Queue* const me),
                int (*isEmptyFunc)(Queue* const me),
                int (*getSizeFunc)(Queue* const me),
                int (*insertFunc)(Queue* const me, int k),
                int (*removeFunc)(Queue* const me)) {
    // initialize attributes
    me->head = 0;
    me->size = 0;
    me->tail = 0;
    // initialize member function pointers
    me->isFull = isFullFunc;
    me->isEmpty = isEmptyFunc;
    me->getSize = getSizeFunc;
    me->insert = insertFunc;
    me->remove = removeFunc;
}

// operation cleanup
void Queue_Cleanup(Queue* const me) {
    printf("call Queue_Cleanup\n");
    printf("nothong to clean.\n");
}

// operation isFull
int Queue_isFull(Queue* const me) {
    return (me->head+1)%QUEUE_SIZE == me->tail;
}

// operation isEmpty
int Queue_isEmpty(Queue* const me) {
    return (me->head == me->tail);
}

// operation getSize
int Queue_getSize(Queue* const me) {
    return me->size;
}

// operation insert
int Queue_insert(Queue* const me, int k) {
    if (!me->isFull(me))
    {
        /* code */
        me->buffer[me->head] = k;
        me->head = (me->head+1)%QUEUE_SIZE;
        ++me->size;
    }
}

// operation remove
int Queue_remove(Queue* const me) {
    int value = -9999;
    if(!me->isEmpty(me)) {
        value = me->buffer[me->tail];
        me->tail = (me->tail+1)%QUEUE_SIZE;
        --me->size;
    }
    return value;
}

// operation create
Queue* Queue_Create(void) {
    Queue* me = (Queue*)malloc(sizeof(Queue));
    if(me!=NULL){
        Queue_Init(me, Queue_isFull, Queue_isEmpty, Queue_getSize, Queue_insert, Queue_remove);
    }
    return me;
}

// operation destroy
void Queue_Destroy(Queue* const me) {
    if (me!=NULL)
    {
        /* code */
        Queue_Cleanup(me);
    }
    free(me);
}
