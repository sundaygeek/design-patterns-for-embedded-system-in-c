#include "Thermometer.h"
#include "CheckTemperature.h"
#include "FurnaceController.h"

static void cleanUpRelations(Thermometer* const me);

void Thermometer_Init(Thermometer* const me) {
    me->itsCheckTemperature = NULL;
    me->itsFurnaceController = NULL;
}

void Thermometer_Cleanup(Thermometer* const me) {
    cleanUpRelations(me);
}

void Thermometer_acquireMeasuredTemperature(Thermometer* const me) {
    /* access the hardware here */
}

int Thermometer_getMeasuredTemperature(Thermometer* const me) {
    if (me->measuredTemp == ~me->invertedMeasuredTemp) {
        CheckTemperature_checkTemperature(me->itsCheckTemperature, me->measuredTemp);
        return me->measuredTemp;
        }
    else {
        FurnaceController_shutDown(me->itsFurnaceController);
        return 0;
        }
}

struct CheckTemperature* Thermometer_getItsCheckTemperature(const Thermometer* const me) {
    return (struct CheckTemperature*)me->itsCheckTemperature;
}

void Thermometer_setItsCheckTemperature(Thermometer* const me, struct CheckTemperature* p_CheckTemperature) {
    me->itsCheckTemperature = p_CheckTemperature;
}

struct FurnaceController* Thermometer_getItsFurnaceController(const Thermometer* const me) {
    return (struct FurnaceController*)me->itsFurnaceController;
}

void Thermometer_setItsFurnaceController(Thermometer* const me, struct FurnaceController* p_FurnaceController) {
    me->itsFurnaceController = p_FurnaceController;
}

Thermometer * Thermometer_Create(void) {
    Thermometer* me = (Thermometer *) malloc(sizeof(Thermometer));
    if(me!=NULL)
        Thermometer_Init(me);
    return me;
}

void Thermometer_Destroy(Thermometer* const me) {
    if(me!=NULL)
        Thermometer_Cleanup(me);
    free(me);
}

static void cleanUpRelations(Thermometer* const me) {
    if(me->itsCheckTemperature != NULL)
        me->itsCheckTemperature = NULL;
    if(me->itsFurnaceController != NULL)
            me->itsFurnaceController = NULL;
}
