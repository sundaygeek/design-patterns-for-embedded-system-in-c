#include "NoNumberState.h"
#include "Context.h"
#include <stdio.h>

static void cleanUpRelations(NoNumberState* const me);

void NoNumberState_Init(NoNumberState* const me) {
    {
        StateActionSet_Init(&(me->aSet));
    }
    me->itsContext = NULL;

    /* set up the aSet function pointers */
    /* remember that the initializer for the StateActionSet */
    /* sets all pointers to NULL as the default */
    me->aSet.evDigitHandler = (ActionPtr1) NoNumberState_evDigit;
    me->aSet.evDotHandler = (ActionPtr0) NoNumberState_evDot;
    me->aSet.evWSHandler = (ActionPtr0) NoNumberState_evWhiteSpace;
    me->aSet.evEOSHandler = (ActionPtr0) NoNumberState_evEndOfString;
    me->aSet.entryAction = (ActionPtr0) NoNumberState_entryAction;
    me->aSet.exitAction = (ActionPtr0) NoNumberState_exitAction;
}

void NoNumberState_Cleanup(NoNumberState* const me) {
    cleanUpRelations(me);
}

void NoNumberState_NoNum2GN(NoNumberState* const me, char c) {
    me->itsContext->ch = c;
    me->itsContext->tensPlace = 10.0;
}

void NoNumberState_entryAction(NoNumberState* const me) {
    me->itsContext->result = 0.0;
}

int NoNumberState_evDigit(NoNumberState* const me, char c) {
    NoNumberState_exitAction(me);
    NoNumberState_NoNum2GN(me, c); /* transition action */
    /* set new state */
    me->itsContext->currentState = GN_PROCESSINGWHOLEPART_STATE;
    return 1; /* processed event */
}

int NoNumberState_evDot(NoNumberState* const me) {
    return 0; /* discarded event */
}

int NoNumberState_evEndOfString(NoNumberState* const me) {
    return 0; /* discarded event */
}

int NoNumberState_evWhiteSpace(NoNumberState* const me) {
    return 0; /* discarded event */
}

void NoNumberState_exitAction(NoNumberState* const me) {

}

struct Context* NoNumberState_getItsContext(const NoNumberState* const me) {
    return (struct Context*)me->itsContext;
}

void NoNumberState_setItsContext(NoNumberState* const me, struct Context* p_Context) {
    me->itsContext = p_Context;
}

NoNumberState * NoNumberState_Create(void) {
    NoNumberState* me = (NoNumberState *) malloc(sizeof(NoNumberState));
    if(me!=NULL)
            NoNumberState_Init(me);
    return me;
}

void NoNumberState_Destroy(NoNumberState* const me) {
    if(me!=NULL)
            NoNumberState_Cleanup(me);
    free(me);
}

static void cleanUpRelations(NoNumberState* const me) {
    if(me->itsContext != NULL)
            me->itsContext = NULL;
}
