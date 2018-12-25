#include "StateActionSet.h"

void StateActionSet_Init(StateActionSet* const me) {
    me->entryAction = NULL;
    me->evDigitHandler = NULL;
    me->evDotHandler = NULL;
    me->evEOSHandler = NULL;
    me->evWSHandler = NULL;
    me->exitAction = NULL;
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
