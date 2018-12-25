#ifndef BCTimer_H
#define BCTimer_H

#include "BCPeriodicPoller.h"
#include <stdio.h>
#include <stdlib.h>

struct BCPeriodicPoller;

typedef struct BCTimer BCTimer;
struct BCTimer
{
    BCPeriodicPoller* poller;
};

void BCTimer_Init(BCTimer* const me);
void BCTimer_Cleanup(BCTimer* const me);

BCTimer* BCTimer_Create();
void BCTimer_Destroy(BCTimer* me);

void BCTimer_startTimer(BCTimer* const me, int pollTime);
void BCTimer_stopTimer(BCTimer* const me);

void BCTimer_installInterruptHandler(BCTimer* const me);
void BCTimer_removeInterruptHandler(BCTimer* const me);

void BCTimer_setItsBCPeriodicPoller(BCTimer* const me, BCPeriodicPoller* const poller);
BCPeriodicPoller* BCTimer_getItsBCPeriodicPoller(BCTimer* const me);

#endif
