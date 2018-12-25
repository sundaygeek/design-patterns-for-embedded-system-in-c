#ifndef GN_ProcessingWholeState_H
#define GN_ProcessingWholeState_H

#include "StatePattern.h"
#include "StateActionSet.h"

struct Context;

typedef struct GN_ProcessingWholeState GN_ProcessingWholeState;
struct GN_ProcessingWholeState {
    struct StateActionSet aSet;
    struct Context* itsContext;
};

/* Constructors and destructors:*/
void GN_ProcessingWholeState_Init(GN_ProcessingWholeState* const me);
void GN_ProcessingWholeState_Cleanup(GN_ProcessingWholeState* const me);

/* Operations */
void GN_ProcessingWholeState_entryAction(GN_ProcessingWholeState* const me);
int GN_ProcessingWholeState_evDigit(GN_ProcessingWholeState* const me, char c);
int GN_ProcessingWholeState_evDot(GN_ProcessingWholeState* const me);
int GN_ProcessingWholeState_evEndOfString(GN_ProcessingWholeState* const me);

int GN_ProcessingWholeState_evWhiteSpace(GN_ProcessingWholeState* const me);
void GN_ProcessingWholeState_exitAction(GN_ProcessingWholeState* const me);
void GN_ProcessingWholeState_printResult(GN_ProcessingWholeState* const me);

struct Context* GN_ProcessingWholeState_getItsContext(const GN_ProcessingWholeState* const me);

void GN_ProcessingWholeState_setItsContext(GN_ProcessingWholeState* const me, struct Context* p_Context);

GN_ProcessingWholeState * GN_ProcessingWholeState_Create(void);

void GN_ProcessingWholeState_Destroy(GN_ProcessingWholeState* const me);

#endif
