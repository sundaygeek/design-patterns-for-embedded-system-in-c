#ifndef GN_ProcessingFractionState_H
#define GN_ProcessingFractionState_H

#include "StatePattern.h"
#include "StateActionSet.h"

struct Context;

typedef struct GN_ProcessingFractionState GN_ProcessingFractionState;
struct GN_ProcessingFractionState {
    struct StateActionSet aSet;
    struct Context* itsContext;
};

/*## operation Init() */
void GN_ProcessingFractionState_Init(GN_ProcessingFractionState* const me);
void GN_ProcessingFractionState_Cleanup(GN_ProcessingFractionState* const me);

/* Operations */

void GN_ProcessingFractionState_Frac2Frac(GN_ProcessingFractionState* const me, char c);
void GN_ProcessingFractionState_entryAction(GN_ProcessingFractionState* const me);
int GN_ProcessingFractionState_evDigit(GN_ProcessingFractionState* const me, char c);
int GN_ProcessingFractionState_evDot(GN_ProcessingFractionState* const me);
int GN_ProcessingFractionState_evEndOfString(GN_ProcessingFractionState* const me);
int GN_ProcessingFractionState_evWhiteSpace(GN_ProcessingFractionState* const me);
void GN_ProcessingFractionState_exitAction(GN_ProcessingFractionState* const me);
void GN_ProcessingFractionState_printResult(GN_ProcessingFractionState* const me);

struct Context* GN_ProcessingFractionState_getItsContext(const GN_ProcessingFractionState* const me);


void GN_ProcessingFractionState_setItsContext(GN_ProcessingFractionState* const me, struct Context* p_Context);

GN_ProcessingFractionState * GN_ProcessingFractionState_Create(void);

void GN_ProcessingFractionState_Destroy(GN_ProcessingFractionState* const me);

#endif
