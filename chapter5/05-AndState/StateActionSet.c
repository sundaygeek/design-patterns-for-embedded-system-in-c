#include "StateActionSet.h"

void StateActionSet_Init(StateActionSet* const me) {
    me->entryAction = NULL;
    me->evAbortHandler = NULL;
    me->evDisableHandler = NULL;
    me->evEnableHandler = NULL;
    me->evErrorHandler = NULL;
    me->evOkHandler = NULL;
    me->evRunHandler = NULL;
    me->evShutDownHandler = NULL;
    me->evWarningHandler = NULL;
    me->exitAction = NULL;
    me->is_inHandler = NULL;
}

void StateActionSet_Cleanup(StateActionSet* const me) {
}

StateActionSet * StateActionSet_Create(void) {
    StateActionSet* me = (StateActionSet *) malloc(sizeof(StateActionSet));
    if(me!=NULL)
        StateActionSet_Init(me);
    return me;
}

void StateActionSet_Destroy(StateActionSet* const me) {
    if(me!=NULL)
        StateActionSet_Cleanup(me);
    free(me);
}
