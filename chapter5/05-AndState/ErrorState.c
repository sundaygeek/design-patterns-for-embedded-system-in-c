#include "ErrorStateClass.h"
#include "LightController.h"

static void cleanUpRelations(ErrorStateClass* const me);

void ErrorStateClass_Init(ErrorStateClass* const me) {
    me->currentState = NULL_ERROR_STATE;
    me->defaultState = ERROR_STATE;
    StateActionSet_Init(&(me->aSet));
    me->itsLightController = NULL;
    /*
    set up the aSet function pointers
    remember that the initializer for the StateActionSet
    sets all pointers to NULL as the default

    Note: In this implementation, pointers are only set to non-NULL
    for actual handlers (except for entry() and exit()). The caller
    can tell if the event is handled by checking if the pointer is NULL.

    The higher level On state handles events reset and evDisable.
    */
    me->aSet.evOkHandler = (ActionPtr0) ErrorStateClass_evOk;
    me->aSet.evWarningHandler = (ActionPtr0) ErrorStateClass_evWarning;
    me->aSet.evErrorHandler = (ActionPtr0) ErrorStateClass_evError;
    me->aSet.evAbortHandler = (ActionPtr0) ErrorStateClass_evAbort;
    me->aSet.entryAction = (ActionPtr0) ErrorStateClass_entryAction;
    me->aSet.exitAction = (ActionPtr0) ErrorStateClass_exitAction;
    me->aSet.is_inHandler = (ActionPtr1) ErrorStateClass_is_in
}

void ErrorStateClass_Cleanup(ErrorStateClass* const me) {
    cleanUpRelations(me);
}


void ErrorStateClass_entryAction(ErrorStateClass* const me) {

}

int ErrorStateClass_evAbort(ErrorStateClass* const me) {
    switch(me->currentState) {
        case OK_STATE:
        case WARNING_STATE:
        case ERROR_STATE:

        case NULL_ERROR_STATE:
            break;
        };
    return 1;
}

int ErrorStateClass_evError(ErrorStateClass* const me) {
    switch(me->currentState) {
        case OK_STATE:
            Light_setColor(me->itsLightController->itsLight, RED);
            me->currentState = ERROR_STATE;
            break;
        case WARNING_STATE:
            Light_setColor(me->itsLightController->itsLight, RED);
            me->currentState = ERROR_STATE;
            break;
        case ERROR_STATE:
        case NULL_ERROR_STATE:
            break;
        };
    return 1;
}

int ErrorStateClass_evOk(ErrorStateClass* const me) {
    switch(me->currentState) {
            Light_setColor(me->itsLightController->itsLight, GREEN);
            me->currentState = OK_STATE;
            break;
        case ERROR_STATE:
            Light_setColor(me->itsLightController->itsLight, GREEN);
            me->currentState = OK_STATE;
            break;
        case WARNING_STATE:
        case OK_STATE:
        case NULL_ERROR_STATE:
            break;
        };
    return 1;
    /*#]*/
}

/*## operation evWarning() */
int ErrorStateClass_evWarning(ErrorStateClass* const me) {
    /*#[ operation evWarning() */
    switch(me->currentState) {
        case OK_STATE:
            Light_setColor(me->itsLightController->itsLight, YELLOW);
            me->currentState = WARNING_STATE;
            break;
        case ERROR_STATE:
            Light_setColor(me->itsLightController->itsLight, YELLOW);
            me->currentState = WARNING_STATE;
            break;
        case WARNING_STATE:
        case NULL_ERROR_STATE:
            break;
        };
    return 1;
}

void ErrorStateClass_exitAction(ErrorStateClass* const me) {

}

int ErrorStateClass_is_in(ErrorStateClass* const me, ErrorStatesType s) {
    return s == me->currentState;
}

struct LightController* ErrorStateClass_getItsLightController(const ErrorStateClass* const me) {
    return (struct LightController*)me->itsLightController;
}

void ErrorStateClass_setItsLightController(ErrorStateClass* const me, struct LightController* p_LightController) {
    me->itsLightController = p_LightController;
}

ErrorStateClass * ErrorStateClass_Create(void) {
    ErrorStateClass* me = (ErrorStateClass *) malloc(sizeof(ErrorStateClass));
    if(me!=NULL)
        ErrorStateClass_Init(me);
    return me;
}

void ErrorStateClass_Destroy(ErrorStateClass* const me) {
    if(me!=NULL)
        ErrorStateClass_Cleanup(me);
    free(me);
}

static void cleanUpRelations(ErrorStateClass* const me) {
    if(me->itsLightController != NULL)
        me->itsLightController = NULL;
}
