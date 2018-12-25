#ifndef LightController_H
#define LightController_H

#include "LightPkg.h"
#include "AndStateList.h"
#include "ErrorStateClass.h"
#include "ModeStateClass.h"

struct Klaxon;
struct Light;
struct Mutex;

typedef struct LightController LightController;
struct LightController {
    struct AndStateList* asList[EMERGENCY_STATE+1];
    HighLevelLightStates currentState;
    struct Klaxon* itsKlaxon;
    struct Light* itsLight;
    struct Mutex* itsMutex;
};

void LightController_evEnable(LightController* const me);
void LightController_evDisable(LightController* const me);
void LightController_reset(LightController* const me);
void LightController_evOk(LightController* const me);
void LightController_evWarning(LightController* const me);
void LightController_evError(LightController* const me);
void LightController_evRun(LightController* const me);
void LightController_evShutDown(LightController* const me);
void LightController_evAbort(LightController* const me);

void LightController_Init(LightController* const me);
void LightController_Cleanup(LightController* const me);

void LightController_enter_OffState(LightController* const me, HighLevelLightStates newState);
void LightController_enter_OnState(LightController* const me, HighLevelLightStates newState);
void LightController_enter_EmergencyState(LightController* const me, HighLevelLightStates newState);

void LightController_exit_OffState(LightController* const me);
void LightController_exit_OnState(LightController* const me);
void LightController_exit_EmergencyState(LightController* const me);
void LightController_enterNestedAndStates(LightController* const me, HighLevelLightStates next);
void LightController_exitNestedAndStates(LightController* const me);

struct Klaxon* LightController_getItsKlaxon(const LightController* const me);
void LightController_setItsKlaxon(LightController* const me, struct Klaxon* p_Klaxon);

struct Light* LightController_getItsLight(const LightController* const me);
void LightController_setItsLight(LightController* const me, struct Light* p_Light);

struct Mutex* LightController_getItsMutex(const LightController* const me);
void LightController_setItsMutex(LightController* const me, struct Mutex* p_Mutex);

LightController * LightController_Create(void);
void LightController_Destroy(LightController* const me);

#endif
