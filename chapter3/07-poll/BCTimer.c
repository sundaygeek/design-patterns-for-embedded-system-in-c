#include "BCTimer.h"

void BCTimer_Init(BCTimer* const me){

}
void BCTimer_Cleanup(BCTimer* const me){

}

BCTimer* BCTimer_Create(){
    BCTimer* me = (BCTimer*)malloc(sizeof(BCTimer));
    if (me != NULL)
    {
        BCTimer_Init(me);
    }
    return me;
}

void BCTimer_Destroy(BCTimer* me){
    if (me != NULL)
    {
        BCTimer_Cleanup(me);
    }
    free(me);
}

void BCTimer_startTimer(BCTimer* const me, int pollTime){

}

void BCTimer_stopTimer(BCTimer* const me){

}

void BCTimer_installInterruptHandler(BCTimer* const me){

}

void BCTimer_removeInterruptHandler(BCTimer* const me){

}

void BCTimer_setItsBCPeriodicPoller(BCTimer* const me, BCPeriodicPoller* const poller){
    me->poller = poller;
}

BCPeriodicPoller* BCTimer_getItsBCPeriodicPoller(BCTimer* const me){
    return me->poller;
}

