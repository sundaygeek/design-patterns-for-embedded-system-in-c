#include "LightController.h"
#include "Klaxon.h"
#include "Light.h"
#include "Mutex.h"

static void cleanUpRelations(LightController* const me);

void LightController_evEnable(LightController* const me) {
    HighLevelLightStates newState;

    Mutex_lock(me->itsMutex);
    switch (me->currentState) {
        case OFF_STATE:
            newState = ON_STATE;
            LightController_exit_OffState(me);

            /* transition to On state */
            Light_turnOn(me->itsLight);
            Light_setColor(me->itsLight, RED);
            Light_setMode(me->itsLight, QUICKLY);

            /* enter new state */
            LightController_enter_OnState(me, newState);
            me->currentState = newState;
            break;
        case ON_STATE:
        case EMERGENCY_STATE:
            break;
        };
    Mutex_release(me->itsMutex);
}

void LightController_evDisable(LightController* const me) {
    HighLevelLightStates newState;

    Mutex_lock(me->itsMutex);
    switch (me->currentState) {
        case ON_STATE:
            newState = OFF_STATE;
            /* exit nested states */
            LightController_exit_OnState(me);

            /* transition to OFF state */
            Light_turnOff(me->itsLight);

            /* enter new state */
            LightController_enter_OffState(me, newState);
            me->currentState = newState;
            break;
        case OFF_STATE:
        case EMERGENCY_STATE:
            break;
        };
    Mutex_release(me->itsMutex);
}

void LightController_reset(LightController* const me) {
    HighLevelLightStates newState;

    Mutex_lock(me->itsMutex);
    switch (me->currentState) {
        case ON_STATE:
            /* exit and-states, then outer state */
            newState = ON_STATE;
            LightController_exit_OnState(me);

            /* note no transition actions */
            /* enter outer state, then and-states */
            LightController_enter_OnState(me, newState);
            me->currentState = newState;
            break;

        case OFF_STATE:
        case EMERGENCY_STATE:
            break;
        };
    Mutex_release(me->itsMutex);
}

void LightController_evOk(LightController* const me) {
    ErrorStateClass* sPtr;
    ActionPtr0 aPtr;
    HighLevelLightStates newState;

    Mutex_lock(me->itsMutex);
    switch (me->currentState) {
        case OFF_STATE:
            break;
        case ON_STATE:
            /* note we're not exiting On state */
            /* so just delegate to and-states */
            newState = me->currentState;
            if (me->asList[newState]) {
                sPtr = me->asList[newState]->andStates[ERRORSTATUS_ANDSTATE];
                if (sPtr) {
                    aPtr = sPtr->aSet.evOkHandler;
                    if (aPtr)
                        aPtr(sPtr);
                    };
                sPtr = me->asList[newState]->andStates[MODE_ANDSTATE];
                if (sPtr) {
                       aPtr = sPtr->aSet.evOkHandler;
                    if (aPtr)
                        aPtr(sPtr);
                    };
                };
            break;
        case EMERGENCY_STATE:
            break;
        };
    Mutex_release(me->itsMutex);
}

void LightController_evWarning(LightController* const me) {
    ErrorStateClass* sPtr;
    ActionPtr0 aPtr;
    HighLevelLightStates newState;

    Mutex_lock(me->itsMutex);
    switch (me->currentState) {
        case OFF_STATE:
            break;
        case ON_STATE:
            /* note we're not exiting On state */
            /* so just delegate to and-states */
            newState = me->currentState;
            if (me->asList[newState]) {
                sPtr = me->asList[newState]->andStates[ERRORSTATUS_ANDSTATE];
                if (sPtr) {
                    aPtr = sPtr->aSet.evWarningHandler;
                    if (aPtr)
                        aPtr(sPtr);
                    };
                sPtr = me->asList[newState]->andStates[MODE_ANDSTATE];
                if (sPtr) {
                       aPtr = sPtr->aSet.evWarningHandler;
                    if (aPtr)
                        aPtr(sPtr);
                    };
                };
            break;
        case EMERGENCY_STATE:
            break;
        };
    Mutex_release(me->itsMutex);
    /*#]*/
}

void LightController_evError(LightController* const me) {
    ErrorStateClass* sPtr;
    ActionPtr0 aPtr;
    HighLevelLightStates newState;

    Mutex_lock(me->itsMutex);
    switch (me->currentState) {
        case OFF_STATE:
            break;
        case ON_STATE:
            /* note we're not exiting On state */
            /* so just delegate to and-states */
            newState = me->currentState;
            if (me->asList[newState]) {
                sPtr = me->asList[newState]->andStates[ERRORSTATUS_ANDSTATE];
                if (sPtr) {
                    aPtr = sPtr->aSet.evErrorHandler;
                    if (aPtr)
                        aPtr(sPtr);
                    };
                sPtr = me->asList[newState]->andStates[MODE_ANDSTATE];
                if (sPtr) {
                       aPtr = sPtr->aSet.evErrorHandler;
                    if (aPtr)
                        aPtr(sPtr);
                    };
                };
            break;
        case EMERGENCY_STATE:
            break;
        };
    Mutex_release(me->itsMutex);
}

void LightController_evRun(LightController* const me) {
    ErrorStateClass* sPtr;
    ActionPtr0 aPtr;
    HighLevelLightStates newState;

    Mutex_lock(me->itsMutex);
    switch (me->currentState) {
        case OFF_STATE:
            break;
        case ON_STATE:
            /* note we're not exiting On state */
            /* so just delegate to and-states */
            newState = me->currentState;
            if (me->asList[newState]) {
                sPtr = me->asList[newState]->andStates[ERRORSTATUS_ANDSTATE];
                if (sPtr) {
                    aPtr = sPtr->aSet.evRunHandler;
                    if (aPtr)
                        aPtr(sPtr);
                    };
                sPtr = me->asList[newState]->andStates[MODE_ANDSTATE];
                if (sPtr) {
                       aPtr = sPtr->aSet.evRunHandler;
                    if (aPtr)
                        aPtr(sPtr);
                    };
                };
            break;
        case EMERGENCY_STATE:
            break;
        };
    Mutex_release(me->itsMutex);
}

void LightController_evShutDown(LightController* const me) {
    ErrorStateClass* sPtr;
    ActionPtr0 aPtr;
    HighLevelLightStates newState;

    Mutex_lock(me->itsMutex);
    switch (me->currentState) {
        case OFF_STATE:
            break;
        case ON_STATE:
            /* note we're not exiting On state */
            /* so just delegate to and-states */
            newState = me->currentState;
            if (me->asList[newState]) {
                sPtr = me->asList[newState]->andStates[ERRORSTATUS_ANDSTATE];
                if (sPtr) {
                    aPtr = sPtr->aSet.evShutDownHandler;
                    if (aPtr)
                        aPtr(sPtr);
                    };
                sPtr = me->asList[newState]->andStates[MODE_ANDSTATE];
                if (sPtr) {
                       aPtr = sPtr->aSet.evShutDownHandler;
                    if (aPtr)
                        aPtr(sPtr);
                    };
                };
            break;
        case EMERGENCY_STATE:
            break;
        };
    Mutex_release(me->itsMutex);
}

void LightController_evAbort(LightController* const me) {
    ErrorStateClass* sPtr;
    ActionPtr1 is_inPtr;
    HighLevelLightStates newState;
    int precond1=0, precond2=0;

    Mutex_lock(me->itsMutex);
    switch (me->currentState) {
        case ON_STATE:
            /* are the preconditions true: */
            /* ie. Error and Operational states? */
            if (me->asList[me->currentState]) {
                sPtr = me->asList[me->currentState]->andStates[ERRORSTATUS_ANDSTATE];
                if (sPtr) {
                    is_inPtr = sPtr->aSet.is_inHandler;
                    if (is_inPtr)
                        precond1 = is_inPtr(sPtr, ERROR_STATE);
                    };
                sPtr = me->asList[me->currentState]->andStates[MODE_ANDSTATE];
                if (sPtr) {
                    is_inPtr = sPtr->aSet.is_inHandler;
                    if (is_inPtr)
                        precond2 = is_inPtr(sPtr, OPERATIONAL_STATE);
                    };
                };
            if (precond1 && precond2)  {
                newState = EMERGENCY_STATE;
                /* exit nested states */
                LightController_exit_OnState(me);

                /* transition to OFF state */
                Light_setColor(me->itsLight, RED);
                Light_setMode(me->itsLight, QUICKLY);
                Klaxon_alarmOn(me->itsKlaxon);

                /* enter new state */
                LightController_enter_EmergencyState(me, newState);
                me->currentState = newState;
            };
            break;
        case OFF_STATE:
        case EMERGENCY_STATE:
            break;
        };
    Mutex_release(me->itsMutex);
}

void LightController_Init(LightController* const me) {
    me->currentState = NULL_STATE;
    me->itsKlaxon = NULL;
    me->itsLight = NULL;
    me->itsMutex = NULL;
    int j;
    HighLevelLightStates st;
    ErrorStateClass* andStatePtr = NULL;

    for (st=NULL_STATE;st<=EMERGENCY_STATE; st++)
    me->asList[st] = NULL;

    /* create all and state lists and states */
    /* In this case, there is only one, the ON_STATE */
    /* which has two nested orthogonal regions */
    me->asList[ON_STATE] = AndStateList_Create();
    me->asList[ON_STATE]->nAndStates = 2;
    andStatePtr = ErrorStateClass_Create();
    if (andStatePtr) {
        me->asList[ON_STATE]->andStates[ERRORSTATUS_ANDSTATE] = andStatePtr;
        andStatePtr->itsLightController = me;
        };
    andStatePtr = (ErrorStateClass*)ModeStateClass_Create();
    if (andStatePtr) {
        me->asList[ON_STATE]->andStates[MODE_ANDSTATE] = andStatePtr;
        andStatePtr->itsLightController = me;
        };

    /* enter initial state */
    me->currentState = OFF_STATE;
    LightController_enter_OffState(me, OFF_STATE);
    /* any nested and states? */
    if (me->asList[me->currentState])
        /* enter the default state in each and-state */
        for (j=0; j<me->asList[me->currentState]->nAndStates; j++)
            me->asList[me->currentState]->andStates[j]->aSet.entryAction(me->asList[me->currentState]->andStates[j]);
}

void LightController_Cleanup(LightController* const me) {
    cleanUpRelations(me);
}

void LightController_enter_OffState(LightController* const me, HighLevelLightStates newState) {
    LightController_enterNestedAndStates(me, newState);
}

void LightController_enter_OnState(LightController* const me, HighLevelLightStates newState) {
    LightController_enterNestedAndStates(me, newState);
}

void LightController_enter_EmergencyState(LightController* const me, HighLevelLightStates newState) {
    LightController_enterNestedAndStates(me, newState);
}

void LightController_exit_OffState(LightController* const me) {
    LightController_exitNestedAndStates(me);
}

void LightController_exit_OnState(LightController* const me) {
    LightController_exitNestedAndStates(me);
}

void LightController_exit_EmergencyState(LightController* const me) {
    LightController_exitNestedAndStates(me);
}

void LightController_enterNestedAndStates(LightController* const me, HighLevelLightStates next) {
    ErrorStateClass* sPtr;
    ActionPtr0 aPtr;
    int j;

    if (me->asList[next]) {
        /* and-states to enter? */
        for (j=0; j<me->asList[next]->nAndStates; j++ ) {
            sPtr = me->asList[next]->andStates[j];
            if (sPtr) {
                aPtr = sPtr->aSet.entryAction;
                if (aPtr)
                    aPtr(sPtr);
                sPtr->currentState = sPtr->defaultState;
                };
            };
        };
}

void LightController_exitNestedAndStates(LightController* const me) {
    ErrorStateClass* sPtr;
    ActionPtr0 aPtr;
    int j;

    if (me->asList[me->currentState]) { /* any nested states to exit? */
        for (j=0; j<me->asList[me->currentState]->nAndStates; j++ ) {
            sPtr = me->asList[me->currentState]->andStates[j];
            if (sPtr) {
                aPtr = sPtr->aSet.exitAction;
                if (aPtr)
                    aPtr(sPtr);
                sPtr->currentState = NULL_ERROR_STATE;
                }; // if sPtr
            }; // for
        };  // if asList
}

struct Klaxon* LightController_getItsKlaxon(const LightController* const me) {
    return (struct Klaxon*)me->itsKlaxon;
}

void LightController_setItsKlaxon(LightController* const me, struct Klaxon* p_Klaxon) {
    me->itsKlaxon = p_Klaxon;
}

struct Light* LightController_getItsLight(const LightController* const me) {
    return (struct Light*)me->itsLight;
}

void LightController_setItsLight(LightController* const me, struct Light* p_Light) {
    me->itsLight = p_Light;
}

struct Mutex* LightController_getItsMutex(const LightController* const me) {
    return (struct Mutex*)me->itsMutex;
}

void LightController_setItsMutex(LightController* const me, struct Mutex* p_Mutex) {
    me->itsMutex = p_Mutex;
}

LightController * LightController_Create(void) {
    LightController* me = (LightController *) malloc(sizeof(LightController));
    if(me!=NULL)
       LightController_Init(me);
    return me;
}

void LightController_Destroy(LightController* const me) {
    if(me!=NULL)
        LightController_Cleanup(me);
    free(me);
}

static void cleanUpRelations(LightController* const me) {
    if(me->itsKlaxon != NULL)
        me->itsKlaxon = NULL;
    if(me->itsLight != NULL)
        me->itsLight = NULL;
    if(me->itsMutex != NULL)
        me->itsMutex = NULL;
}
