#include "BCPeriodicPoller.h"
#include "BCTimer.h"
#include "BreathingCircuitSensor.h"
#include "MedicalDisplay.h"

static void cleanUpRelations(BCPeriodicPoller* const me);

void BCPeriodicPoller_Init(BCPeriodicPoller* const me) {
    me->pollTime = DEFAULT_POLL_TIME;
    me->itsBCTimer = NULL;
    int pos;
    for(pos = 0; pos < 3; ++pos)
        me->itsBreathingCircuitSensor[pos] = NULL;
    me->itsMedicalDisplay = NULL;
    BCTimer_installInterruptHandler(me->itsBCTimer);
    me->pollTime = DEFAULT_POLL_TIME;
}

void BCPeriodicPoller_Cleanup(BCPeriodicPoller* const me) {
    BCTimer_stopTimer(me->itsBCTimer);
    BCTimer_removeInterruptHandler(me->itsBCTimer);
    cleanUpRelations(me);
}

void BCPeriodicPoller_poll(BCPeriodicPoller* const me) {
     int state, data;
     data = BreathingCircuitSensor_getData(me->itsBreathingCircuitSensor[0]);
     MedicalDisplay_showO2Concentration(me->itsMedicalDisplay, data);

     data = BreathingCircuitSensor_getData(me->itsBreathingCircuitSensor[1]);
     state = BreathingCircuitSensor_getState(me->itsBreathingCircuitSensor[1]);
     MedicalDisplay_showGasFlow(me->itsMedicalDisplay, data);
     MedicalDisplay_showGasFlowStatus(me->itsMedicalDisplay, state);

     data = BreathingCircuitSensor_getData(me->itsBreathingCircuitSensor[2]);
     MedicalDisplay_showCircuitPressure(me->itsMedicalDisplay, data);
}

void BCPeriodicPoller_setPollTime(BCPeriodicPoller* const me, unsigned long t) {
    me->pollTime = t;
}

void BCPeriodicPoller_startPolling(BCPeriodicPoller* const me) {
    BCTimer_startTimer(me->itsBCTimer, me->pollTime);
}

void BCPeriodicPoller_stopPolling(BCPeriodicPoller* const me) {
    BCTimer_stopTimer(me->itsBCTimer);
}

struct BCTimer* BCPeriodicPoller_getItsBCTimer(const BCPeriodicPoller* const me) {
    return (struct BCTimer*)me->itsBCTimer;
}

void BCPeriodicPoller_setItsBCTimer(BCPeriodicPoller* const me, struct BCTimer* p_BCTimer) {
    if(p_BCTimer != NULL)
        {
            BCTimer_setItsBCPeriodicPoller(p_BCTimer, me);
        }
    BCPeriodicPoller_setItsBCTimer1(me, p_BCTimer);
}

int BCPeriodicPoller_getItsBreathingCircuitSensor(const BCPeriodicPoller* const me) {
    int iter = 0;
    return iter;
}

void BCPeriodicPoller_addItsBreathingCircuitSensor(BCPeriodicPoller* const me, struct BreathingCircuitSensor * p_BreathingCircuitSensor) {
    int pos;
    for(pos = 0; pos < 3; ++pos) {
        if (!me->itsBreathingCircuitSensor[pos]) {
            me->itsBreathingCircuitSensor[pos] = p_BreathingCircuitSensor;
            break;
        }
    }
}

void BCPeriodicPoller_removeItsBreathingCircuitSensor(BCPeriodicPoller* const me, struct BreathingCircuitSensor * p_BreathingCircuitSensor) {
    int pos;
    for(pos = 0; pos < 3; ++pos) {
        if (me->itsBreathingCircuitSensor[pos] == p_BreathingCircuitSensor) {
            me->itsBreathingCircuitSensor[pos] = NULL;
        }
    }
}

void BCPeriodicPoller_clearItsBreathingCircuitSensor(BCPeriodicPoller* const me) {
    {
        int pos;
        for(pos = 0; pos < 3; ++pos)
        {
            me->itsBreathingCircuitSensor[pos] = NULL;
        }
    }
}

struct MedicalDisplay* BCPeriodicPoller_getItsMedicalDisplay(const BCPeriodicPoller* const me) {
    return (struct MedicalDisplay*)me->itsMedicalDisplay;
}

void BCPeriodicPoller_setItsMedicalDisplay(BCPeriodicPoller* const me, struct MedicalDisplay* p_MedicalDisplay) {
    me->itsMedicalDisplay = p_MedicalDisplay;
}

BCPeriodicPoller * BCPeriodicPoller_Create(void) {
    BCPeriodicPoller* me = (BCPeriodicPoller *) malloc(sizeof(BCPeriodicPoller));
    if(me!=NULL)
        {
            BCPeriodicPoller_Init(me);
        }
    return me;
}

void BCPeriodicPoller_Destroy(BCPeriodicPoller* const me) {
    if(me!=NULL)
        {
            BCPeriodicPoller_Cleanup(me);
        }
    free(me);
}

static void cleanUpRelations(BCPeriodicPoller* const me) {
    if(me->itsBCTimer != NULL)
        {
            struct BCPeriodicPoller* p_BCPeriodicPoller = BCTimer_getItsBCPeriodicPoller(me->itsBCTimer);
            if(p_BCPeriodicPoller != NULL)
                {
                    BCTimer_setItsBCPeriodicPoller(me->itsBCTimer, NULL);
                }
            me->itsBCTimer = NULL;
        }

    if(me->itsMedicalDisplay != NULL)
        {
            me->itsMedicalDisplay = NULL;
        }
}

void BCPeriodicPoller_setItsBCTimer2(BCPeriodicPoller* const me, struct BCTimer* p_BCTimer) {
    me->itsBCTimer = p_BCTimer;
}

void BCPeriodicPoller_setItsBCTimer1(BCPeriodicPoller* const me, struct BCTimer* p_BCTimer) {
    if(me->itsBCTimer != NULL)
        {
            BCTimer_setItsBCPeriodicPoller(me->itsBCTimer, NULL);
        }
    BCPeriodicPoller_setItsBCTimer2(me, p_BCTimer);
}

void BCPeriodicPoller_clearItsBCTimer(BCPeriodicPoller* const me) {
    me->itsBCTimer = NULL;
}
