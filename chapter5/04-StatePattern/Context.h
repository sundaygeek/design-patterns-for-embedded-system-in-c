#ifndef Context_H
#define Context_H

#include "StatePattern.h"
#include "GN_ProcessingFractionState.h"
#include "GN_ProcessingWholeState.h"
#include "NoNumberState.h"

struct Mutex;


typedef struct Context Context;
struct Context {
    char ch;
    TSTATETYPE currentState;
    double result;
    struct NoNumberState* stateList[GN_PROCESSINGFRACTIONALPART_STATE+1];
    double tensPlace;
    struct Mutex* itsMutex;
};

/* Constructors and destructors:*/
void Context_Init(Context* const me);
void Context_Cleanup(Context* const me);

/* Operations */
void Context_evDigit(Context* const me, char c);
void Context_evDot(Context* const me);
void Context_evEndOfString(Context* const me);
void Context_evWhiteSpace(Context* const me);


struct Mutex* Context_getItsMutex(const Context* const me);
void Context_setItsMutex(Context* const me, struct Mutex* p_Mutex);

Context * Context_Create(void);
void Context_Destroy(Context* const me);

#endif
