#include "CheckTemperature.h"
#include "FurnaceController.h"

static void cleanUpRelations(CheckTemperature* const me);

void CheckTemperature_Init(CheckTemperature* const me) {
    me->maximumTemp = 130;
    me->minimumTemp = 0;
    me->itsFurnaceController = NULL;
}

void CheckTemperature_Cleanup(CheckTemperature* const me) {
    cleanUpRelations(me);
}

void CheckTemperature_checkTemperature(CheckTemperature* const me, int temp) {
    if (temp < me->minimumTemp)
        FurnaceController_emergencyRestart(me->itsFurnaceController);
    if (temp > me->maximumTemp)
        FurnaceController_shutDown(me->itsFurnaceController);
}

struct FurnaceController* CheckTemperature_getItsFurnaceController(const CheckTemperature* const me) {
    return (struct FurnaceController*)me->itsFurnaceController;
}

void CheckTemperature_setItsFurnaceController(CheckTemperature* const me, struct FurnaceController* p_FurnaceController) {
    me->itsFurnaceController = p_FurnaceController;
}

CheckTemperature * CheckTemperature_Create(void) {
    CheckTemperature* me = (CheckTemperature *) malloc(sizeof(CheckTemperature));
    if(me!=NULL)
        CheckTemperature_Init(me);
    return me;
}

void CheckTemperature_Destroy(CheckTemperature* const me) {
    if(me!=NULL)
        CheckTemperature_Cleanup(me);
    free(me);
}

static void cleanUpRelations(CheckTemperature* const me) {
    if(me->itsFurnaceController != NULL)
            me->itsFurnaceController = NULL;
}
