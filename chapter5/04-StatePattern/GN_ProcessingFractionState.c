#include "GN_ProcessingFractionState.h"
#include "Context.h"

static void cleanUpRelations(GN_ProcessingFractionState* const me);

void GN_ProcessingFractionState_Init(GN_ProcessingFractionState* const me) {
    StateActionSet_Init(&(me->aSet));
    me->itsContext = NULL;

    /* set up the aSet function pointers */
    /* remember that the initializer for the StateActionSet */
    /* sets all pointers to NULL as the default */
    me->aSet.evDigitHandler = (ActionPtr1) GN_ProcessingFractionState_evDigit;
    me->aSet.evDotHandler = (ActionPtr0) GN_ProcessingFractionState_evDot;
    me->aSet.evWSHandler = (ActionPtr0) GN_ProcessingFractionState_evWhiteSpace;
    me->aSet.evEOSHandler = (ActionPtr0) GN_ProcessingFractionState_evEndOfString;
    me->aSet.entryAction = (ActionPtr0) GN_ProcessingFractionState_entryAction;
    me->aSet.exitAction = (ActionPtr0) GN_ProcessingFractionState_exitAction;
}

void GN_ProcessingFractionState_Cleanup(GN_ProcessingFractionState* const me) {
    cleanUpRelations(me);
}

void GN_ProcessingFractionState_Frac2Frac(GN_ProcessingFractionState* const me, char c) {
    me->itsContext->ch = c;
    me->itsContext->result += digit(me->itsContext->ch)/me->itsContext->tensPlace;
    me->itsContext->tensPlace *= 10;
}

void GN_ProcessingFractionState_entryAction(GN_ProcessingFractionState* const me) {

}

int GN_ProcessingFractionState_evDigit(GN_ProcessingFractionState* const me, char c) {
    GN_ProcessingFractionState_entryAction(me);
    GN_ProcessingFractionState_Frac2Frac(me, c); /* transition action */
    /* note: state doesn't change, so the same */
    /* state is reentered */
    return 1; /* event handled */
}

int GN_ProcessingFractionState_evDot(GN_ProcessingFractionState* const me) {
    return 0; /* event discarded */
}

int GN_ProcessingFractionState_evEndOfString(GN_ProcessingFractionState* const me) {
    GN_ProcessingFractionState_exitAction(me);
    GN_ProcessingFractionState_printResult(me); /* transition action */
    me->itsContext->currentState = NONUMBER_STATE;
    return 1; /* event handled */
}

int GN_ProcessingFractionState_evWhiteSpace(GN_ProcessingFractionState* const me) {
    GN_ProcessingFractionState_exitAction(me);
    GN_ProcessingFractionState_printResult(me); /* transition action */
    me->itsContext->currentState = NONUMBER_STATE;
    return 1; /* event handled */
}

void GN_ProcessingFractionState_exitAction(GN_ProcessingFractionState* const me) {

}

void GN_ProcessingFractionState_printResult(GN_ProcessingFractionState* const me) {
    printf("Number: %g\n", me->itsContext->result);
}

struct Context* GN_ProcessingFractionState_getItsContext(const GN_ProcessingFractionState* const me) {
    return (struct Context*)me->itsContext;
}

void GN_ProcessingFractionState_setItsContext(GN_ProcessingFractionState* const me, struct Context* p_Context) {
    me->itsContext = p_Context;
}

GN_ProcessingFractionState * GN_ProcessingFractionState_Create(void) {
    GN_ProcessingFractionState* me = (GN_ProcessingFractionState *) malloc(sizeof(GN_ProcessingFractionState));
    if(me!=NULL)
            GN_ProcessingFractionState_Init(me);
    return me;
}

void GN_ProcessingFractionState_Destroy(GN_ProcessingFractionState* const me) {
    if(me!=NULL)
            GN_ProcessingFractionState_Cleanup(me);
    free(me);
}

static void cleanUpRelations(GN_ProcessingFractionState* const me) {
    if(me->itsContext != NULL)
            me->itsContext = NULL;
}
