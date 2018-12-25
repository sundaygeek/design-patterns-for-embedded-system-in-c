#ifndef ThreadBarrier_H
#define ThreadBarrier_H

/*## auto_generated */
#include <oxf/Ric.h>
/*## auto_generated */
#include "RendezvousExample.h"
/*## auto_generated */
#include <oxf/RiCTask.h>
/*## package RendezvousPattern::RendezvousExample */

/*## class ThreadBarrier */
typedef struct ThreadBarrier ThreadBarrier;
struct ThreadBarrier {
    int currentCount;
    int expectedCount;
    OSSemaphore* barrier;
    OSSemaphore* mutex;
};

/* Constructors and destructors:*/
void ThreadBarrier_Init(ThreadBarrier* const me);
void ThreadBarrier_Cleanup(ThreadBarrier* const me);

/* Operations */
void ThreadBarrier_reset(ThreadBarrier* const me, int x);
void ThreadBarrier_synchronize(ThreadBarrier* const me);
ThreadBarrier * ThreadBarrier_Create(void);
void ThreadBarrier_Destroy(ThreadBarrier* const me);

#endif
