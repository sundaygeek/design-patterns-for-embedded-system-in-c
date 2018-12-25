#ifndef ErrorStateClass_H
#define ErrorStateClass_H

#include "LightPkg.h"
#include "StateActionSet.h"

struct LightController;


typedef struct ErrorStateClass ErrorStateClass;
struct ErrorStateClass {
    struct StateActionSet aSet;
    ErrorStatesType currentState;
    ErrorStatesType defaultState;
    struct LightController* itsLightController;
};



void ErrorStateClass_Init(ErrorStateClass* const me);
void ErrorStateClass_Cleanup(ErrorStateClass* const me);


/* Operations */
void ErrorStateClass_entryAction(ErrorStateClass* const me);
int ErrorStateClass_evAbort(ErrorStateClass* const me);
int ErrorStateClass_evError(ErrorStateClass* const me);
int ErrorStateClass_evOk(ErrorStateClass* const me);
int ErrorStateClass_evWarning(ErrorStateClass* const me);
void ErrorStateClass_exitAction(ErrorStateClass* const me);
int ErrorStateClass_is_in(ErrorStateClass* const me, ErrorStatesType s);

struct LightController* ErrorStateClass_getItsLightController(const ErrorStateClass* const me);

void ErrorStateClass_setItsLightController(ErrorStateClass* const me, struct LightController* p_LightController);

ErrorStateClass * ErrorStateClass_Create(void);

void ErrorStateClass_Destroy(ErrorStateClass* const me);
#endif
