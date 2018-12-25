#include "Thermostat.h"
#include "FurnaceController.h"

static void cleanUpRelations(Thermostat* const me);

void Thermostat_Init(Thermostat* const me) {
    me->defaultTempSetting = 70;
    me->invertedDefaultTemp = ~70;
    me->itsFurnaceController = NULL;
}

void Thermostat_Cleanup(Thermostat* const me) {
    cleanUpRelations(me);
}

int Thermostat_getDesiredTemperature(Thermostat* const me) {
    if (me->desiredTemp == ~me->invertedDesiredTemp)
        return me->desiredTemp;
    else
        if (me->defaultTempSetting == ~me->invertedDefaultTemp) {
            Thermostat_setDesiredTemperature(me, me->defaultTempSetting);
            return me->defaultTempSetting;
            }
        else {
            FurnaceController_shutDown(me->itsFurnaceController);
            return me->defaultTempSetting;
            };
}

void Thermostat_setDesiredTemperature(Thermostat* const me, int temp) {
    if (me->desiredTemp == ~me->invertedDesiredTemp) {
        me->desiredTemp = temp;
        me->invertedDesiredTemp = ~temp;
        if (me->desiredTemp == ~me->invertedDesiredTemp)
            return;
        }
    else
        FurnaceController_shutDown(me->itsFurnaceController);
}

struct FurnaceController* Thermostat_getItsFurnaceController(const Thermostat* const me) {
    return (struct FurnaceController*)me->itsFurnaceController;
}

void Thermostat_setItsFurnaceController(Thermostat* const me, struct FurnaceController* p_FurnaceController) {
    me->itsFurnaceController = p_FurnaceController;
}

Thermostat * Thermostat_Create(void) {
    Thermostat* me = (Thermostat *) malloc(sizeof(Thermostat));
    if(me!=NULL)
        Thermostat_Init(me);
    return me;
}

void Thermostat_Destroy(Thermostat* const me) {
    if(me!=NULL)
        Thermostat_Cleanup(me);
    free(me);
}

static void cleanUpRelations(Thermostat* const me) {
    if(me->itsFurnaceController != NULL)
        me->itsFurnaceController = NULL;
}
