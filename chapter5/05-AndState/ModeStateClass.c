#include "ModeStateClass.h"
#include "LightController.h"

static void cleanUpRelations(ModeStateClass* const me);

void ModeStateClass_Init(ModeStateClass* const me) {
    me->currentState = NULL_MODE_STATE;
    me->defaultState = STARTINGUP_STATE;
    {
        StateActionSet_Init(&(me->aSet));
    }
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
    me->aSet.evRunHandler = (ActionPtr0) ModeStateClass_evRun;
    me->aSet.evShutDownHandler = (ActionPtr0) ModeStateClass_evShutDown;
    me->aSet.evAbortHandler = (ActionPtr0) ModeStateClass_evAbort;
    me->aSet.entryAction = (ActionPtr0) ModeStateClass_entryAction;
    me->aSet.exitAction = (ActionPtr0) ModeStateClass_exitAction;
    me->aSet.is_inHandler = (ActionPtr1) ModeStateClass_is_in;
}

void ModeStateClass_Cleanup(ModeStateClass* const me) {
    cleanUpRelations(me);
}

void ModeStateClass_entryAction(ModeStateClass* const me) {

}

int ModeStateClass_evAbort(ModeStateClass* const me) {
    return 1;
}

int ModeStateClass_evRun(ModeStateClass* const me) {
    switch (me->currentState) {
        case STARTINGUP_STATE:
            Light_setMode(me->itsLightController->itsLight, STEADY);
            me->currentState = OPERATIONAL_STATE;
            break;
        case SHUTTINGDOWN_STATE:
            Light_setMode(me->itsLightController->itsLight, QUICKLY);
            me->currentState = STARTINGUP_STATE;
            break;
        case OPERATIONAL_STATE:
        case NULL_MODE_STATE:
            break;
        };
    return 1;
}

int ModeStateClass_evShutDown(ModeStateClass* const me) {
    switch (me->currentState) {
        case OPERATIONAL_STATE:
             Light_setMode(me->itsLightController->itsLight, SLOWLY);
             me->currentState = SHUTTINGDOWN_STATE;
            break;
        case STARTINGUP_STATE:
            Light_setMode(me->itsLightController->itsLight, SLOWLY);
             me->currentState = SHUTTINGDOWN_STATE;
            break;
        case SHUTTINGDOWN_STATE:
            break;
        case NULL_MODE_STATE:
            break;
        };
    return 1;
}

void ModeStateClass_exitAction(ModeStateClass* const me) {

}


int ModeStateClass_is_in(ModeStateClass* const me, ModeStatesType s) {
    return s == me->currentState;
}

struct LightController* ModeStateClass_getItsLightController(const ModeStateClass* const me) {
    return (struct LightController*)me->itsLightController;
}

void ModeStateClass_setItsLightController(ModeStateClass* const me, struct LightController* p_LightController) {
    me->itsLightController = p_LightController;
}

ModeStateClass * ModeStateClass_Create(void) {
    ModeStateClass* me = (ModeStateClass *) malloc(sizeof(ModeStateClass));
    if(me!=NULL)
        ModeStateClass_Init(me);
    return me;
}

void ModeStateClass_Destroy(ModeStateClass* const me) {
    if(me!=NULL)
        ModeStateClass_Cleanup(me);
    free(me);
}

static void cleanUpRelations(ModeStateClass* const me) {
    if(me->itsLightController != NULL)
        me->itsLightController = NULL;
}
