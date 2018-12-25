#include "ThreadBarrier.h"

void ThreadBarrier_Init(ThreadBarrier* const me) {
    me->currentCount = 0;
    me->expectedCount = 3;
    me->mutex = OSSemaphore_Create();
    me->barrier = OSSemaphore_Create();
    if (me->barrier) {
        OSSemaphore_lock(me->barrier);
        printf("BARRIER IS LOCKED FIRST TIME\n");
    };
}

void ThreadBarrier_Cleanup(ThreadBarrier* const me) {
    OSSemaphore_Destroy(me->barrier);
    OSSemaphore_Destroy(me->mutex);
}

void ThreadBarrier_reset(ThreadBarrier* const me, int x) {
    me->expectedCount = x;
    me->currentCount = 0;
}

void ThreadBarrier_synchronize(ThreadBarrier* const me) {
    /*
        protect the critical region around
        the currentCount
    */
    OSSemaphore_lock(me->mutex);
        ++me->currentCount;     /* critical region */
    OSSemaphore_release(me->mutex);

    /*
        are conditions for unblocking met?
        if so, then release the first blocked
        thread or the highest priority blocked
        thread (depending on the OS)
     */
    if (me->currentCount == me->expectedCount) {
        printf("Conditions met\n");
        OSSemaphore_release(me->barrier);
    };

    /*
        lock the semaphore and when released
        then release it for the next blocked thread
    */
    OSSemaphore_lock(me->barrier);
    OSSemaphore_release(me->barrier);

}

ThreadBarrier * ThreadBarrier_Create(void) {
    ThreadBarrier* me = (ThreadBarrier *) malloc(sizeof(ThreadBarrier));
    if(me!=NULL)
              ThreadBarrier_Init(me);
    return me;
}

void ThreadBarrier_Destroy(ThreadBarrier* const me) {
    if(me!=NULL)
        ThreadBarrier_Cleanup(me);
    free(me);
}
