#include "GN_ProcessingWholeState.h"
#include "Context.h"

static void cleanUpRelations(GN_ProcessingWholeState* const me);

void GN_ProcessingWholeState_Init(GN_ProcessingWholeState* const me) {
    StateActionSet_Init(&(me->aSet));
    me->itsContext = NULL;

    /* set up the aSet function pointers */
    /* remember that the initializer for the StateActionSet */
    /* sets all pointers to NULL as the default */
    me->aSet.evDigitHandler = (ActionPtr1) GN_ProcessingWholeState_evDigit;
    me->aSet.evDotHandler = (ActionPtr0) GN_ProcessingWholeState_evDot;
    me->aSet.evWSHandler = (ActionPtr0) GN_ProcessingWholeState_evWhiteSpace;
    me->aSet.evEOSHandler = (ActionPtr0) GN_ProcessingWholeState_evEndOfString;
    me->aSet.entryAction = (ActionPtr0) GN_ProcessingWholeState_entryAction;
    me->aSet.exitAction = (ActionPtr0) GN_ProcessingWholeState_exitAction;
}

void GN_ProcessingWholeState_Cleanup(GN_ProcessingWholeState* const me) {
    cleanUpRelations(me);
}

void GN_ProcessingWholeState_entryAction(GN_ProcessingWholeState* const me) {
    me->itsContext->result = me->itsContext->result*10 + digit(me->itsContext->ch);
}

int GN_ProcessingWholeState_evDigit(GN_ProcessingWholeState* const me, char c) {
    GN_ProcessingWholeState_exitAction(me);
    me->itsContext->ch = c; /* transitiona action */
    /* note: same state is reentered in this case */
    /* so no change to itsContext->currentState */
    return 1; /* event handled */
}

int GN_ProcessingWholeState_evDot(GN_ProcessingWholeState* const me) {
    GN_ProcessingWholeState_exitAction(me);
    /* no transition action */
    me->itsContext->currentState = GN_PROCESSINGFRACTIONALPART_STATE;
    return 1; /* event handled */
}

int GN_ProcessingWholeState_evEndOfString(GN_ProcessingWholeState* const me) {
    GN_ProcessingWholeState_exitAction(me);
    GN_ProcessingWholeState_printResult(me); /* transition action */
    me->itsContext->currentState = NONUMBER_STATE;
    return 1; /* event handled */
}

int GN_ProcessingWholeState_evWhiteSpace(GN_ProcessingWholeState* const me) {
    GN_ProcessingWholeState_exitAction(me);
    GN_ProcessingWholeState_printResult(me); /* transition action */
    me->itsContext->currentState = NONUMBER_STATE;
    return 1; /* event handled */
}

/*## operation exitAction() */
void GN_ProcessingWholeState_exitAction(GN_ProcessingWholeState* const me) {

}

void GN_ProcessingWholeState_printResult(GN_ProcessingWholeState* const me) {
    printf("Number: %g\n", me->itsContext->result);
}

struct Context* GN_ProcessingWholeState_getItsContext(const GN_ProcessingWholeState* const me) {
    return (struct Context*)me->itsContext;
}

void GN_ProcessingWholeState_setItsContext(GN_ProcessingWholeState* const me, struct Context* p_Context) {
    me->itsContext = p_Context;
}

GN_ProcessingWholeState * GN_ProcessingWholeState_Create(void) {
    GN_ProcessingWholeState* me = (GN_ProcessingWholeState *) malloc(sizeof(GN_ProcessingWholeState));
    if(me!=NULL)
            GN_ProcessingWholeState_Init(me);
    return me;
}

void GN_ProcessingWholeState_Destroy(GN_ProcessingWholeState* const me) {
    if(me!=NULL)
            GN_ProcessingWholeState_Cleanup(me);
    free(me);
}

static void cleanUpRelations(GN_ProcessingWholeState* const me) {
    if(me->itsContext != NULL)
            me->itsContext = NULL;
}
