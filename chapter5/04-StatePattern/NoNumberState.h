#ifndef NoNumberState_H
#define NoNumberState_H

#include "StatePattern.h"
#include "StateActionSet.h"

struct Context;

typedef struct NoNumberState NoNumberState;
struct NoNumberState {
    struct StateActionSet aSet;
    struct Context* itsContext;
};


/* Constructors and destructors:*/
void NoNumberState_Init(NoNumberState* const me);
void NoNumberState_Cleanup(NoNumberState* const me);

/* Operations */
void NoNumberState_NoNum2GN(NoNumberState* const me, char c);
void NoNumberState_entryAction(NoNumberState* const me);
int NoNumberState_evDigit(NoNumberState* const me, char c);
int NoNumberState_evDot(NoNumberState* const me);
int NoNumberState_evEndOfString(NoNumberState* const me);
int NoNumberState_evWhiteSpace(NoNumberState* const me);
void NoNumberState_exitAction(NoNumberState* const me);


struct Context* NoNumberState_getItsContext(const NoNumberState* const me);
void NoNumberState_setItsContext(NoNumberState* const me, struct Context* p_Context);
NoNumberState * NoNumberState_Create(void);
void NoNumberState_Destroy(NoNumberState* const me);

#endif
