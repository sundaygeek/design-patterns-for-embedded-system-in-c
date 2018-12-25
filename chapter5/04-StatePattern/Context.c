#include "Context.h"
#include "Mutex.h"

static void cleanUpRelations(Context* const me);

void Context_Init(Context* const me) {
    me->ch = 'x';
    me->currentState = NULL_STATE;
    me->result = 0.0;
    me->tensPlace = 10.0;
    me->itsMutex = NULL;

    me->stateList[NULL_STATE] = NULL;

    /* set up state list */
    me->stateList[NONUMBER_STATE] = NoNumberState_Create();
    me->stateList[NONUMBER_STATE]->itsContext = me;
    me->stateList[GN_PROCESSINGWHOLEPART_STATE] =  (NoNumberState*) GN_ProcessingWholeState_Create();
    me->stateList[GN_PROCESSINGWHOLEPART_STATE]->itsContext = me;
    me->stateList[GN_PROCESSINGFRACTIONALPART_STATE] =  (NoNumberState*) GN_ProcessingFractionState_Create();
    me->stateList[GN_PROCESSINGFRACTIONALPART_STATE]->itsContext = me;

    /* enter starting state */
    me->stateList[NONUMBER_STATE]->aSet.entryAction(me->stateList[NONUMBER_STATE]);
}

void Context_Cleanup(Context* const me) {
    NoNumberState_Destroy(me->stateList[NONUMBER_STATE]);
    GN_ProcessingWholeState_Destroy((GN_ProcessingWholeState *)me->stateList[GN_PROCESSINGWHOLEPART_STATE]);
    GN_ProcessingFractionState_Destroy((GN_ProcessingFractionState *)me->stateList[GN_PROCESSINGFRACTIONALPART_STATE]);

    cleanUpRelations(me);
}

void Context_evDigit(Context* const me, char c) {
    Mutex_lock(me->itsMutex);
    /* this call does the entry and transition actions */
    /* and updates the currentState variable */
    if (me->stateList[me->currentState]->aSet.evDigitHandler(me->stateList[me->currentState], c))
        me->stateList[me->currentState]->aSet.entryAction(me->stateList[me->currentState]);
    Mutex_release(me->itsMutex);
}

void Context_evDot(Context* const me) {
    Mutex_lock(me->itsMutex);
    /* this call does the entry and transition actions */
    /* and updates the currentState variable */
    if (me->stateList[me->currentState]->aSet.evDotHandler(me->stateList[me->currentState]))
        me->stateList[me->currentState]->aSet.entryAction(me->stateList[me->currentState]);
    Mutex_release(me->itsMutex);
}

void Context_evEndOfString(Context* const me) {
    Mutex_lock(me->itsMutex);
    /* this call does the entry and transition actions */
    /* and updates the currentState variable */
    if (me->stateList[me->currentState]->aSet.evEOSHandler(me->stateList[me->currentState]))
        me->stateList[me->currentState]->aSet.entryAction(me->stateList[me->currentState]);
    Mutex_release(me->itsMutex);
}

void Context_evWhiteSpace(Context* const me) {
    Mutex_lock(me->itsMutex);
    /* this call does the entry and transition actions */
    /* and updates the currentState variable */
    if (me->stateList[me->currentState]->aSet.evWSHandler(me->stateList[me->currentState]))
        me->stateList[me->currentState]->aSet.entryAction(me->stateList[me->currentState]);
    Mutex_release(me->itsMutex);
}

struct Mutex* Context_getItsMutex(const Context* const me) {
    return (struct Mutex*)me->itsMutex;
}

void Context_setItsMutex(Context* const me, struct Mutex* p_Mutex) {
    me->itsMutex = p_Mutex;
}

Context * Context_Create(void) {
    Context* me = (Context *) malloc(sizeof(Context));
    if(me!=NULL)
            Context_Init(me);
    return me;
}

void Context_Destroy(Context* const me) {
    if(me!=NULL)
            Context_Cleanup(me);
    free(me);
}

static void cleanUpRelations(Context* const me) {
    if(me->itsMutex != NULL)
            me->itsMutex = NULL;
}
