#ifndef ModeStateClass_H
#define ModeStateClass_H

#include "LightPkg.h"
#include "StateActionSet.h"
struct LightController;

typedef struct ModeStateClass ModeStateClass;
struct ModeStateClass {
    struct StateActionSet aSet;
    ModeStatesType currentState;
    ModeStatesType defaultState;
    struct LightController* itsLightController;
};

void ModeStateClass_Init(ModeStateClass* const me);
void ModeStateClass_Cleanup(ModeStateClass* const me);

/* Operations */
void ModeStateClass_entryAction(ModeStateClass* const me);
int ModeStateClass_evAbort(ModeStateClass* const me);
int ModeStateClass_evRun(ModeStateClass* const me);
int ModeStateClass_evShutDown(ModeStateClass* const me);
void ModeStateClass_exitAction(ModeStateClass* const me);
int ModeStateClass_is_in(ModeStateClass* const me, ModeStatesType s);

struct LightController* ModeStateClass_getItsLightController(const ModeStateClass* const me);
void ModeStateClass_setItsLightController(ModeStateClass* const me, struct LightController* p_LightController);

ModeStateClass * ModeStateClass_Create(void);
void ModeStateClass_Destroy(ModeStateClass* const me);
#endif
