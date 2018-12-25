#include "AndStateList.h"
#include "ErrorStateClass.h"


void AndStateList_Init(AndStateList* const me) {
    me->nAndStates = 0;
    int j;
    for (j=0; j<MAX_ANDSTATES; j++)
        me->andStates[j] = NULL;
}

void AndStateList_Cleanup(AndStateList* const me) {
}

AndStateList * AndStateList_Create(void) {
    AndStateList* me = (AndStateList *) malloc(sizeof(AndStateList));
    if(me!=NULL)
        AndStateList_Init(me);
    return me;
}

void AndStateList_Destroy(AndStateList* const me) {
    if(me!=NULL)
        AndStateList_Cleanup(me);
    free(me);
}
