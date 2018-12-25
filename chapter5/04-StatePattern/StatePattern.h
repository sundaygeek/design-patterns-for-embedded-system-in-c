#ifndef StatePattern_H
#define StatePattern_H

struct Context;
struct GN_ProcessingFractionState;
struct GN_ProcessingWholeState;
struct Mutex;
struct NoNumberState;
struct SPClient;
struct StateActionSet;
struct StatePatternBulder;

typedef enum TSTATETYPE {
    NULL_STATE,
    NONUMBER_STATE,
    GN_PROCESSINGWHOLEPART_STATE,
    GN_PROCESSINGFRACTIONALPART_STATE
} TSTATETYPE;

typedef int (*ActionPtr0)(void*);
typedef int (*ActionPtr1)(void*, char);

int digit(char c); /* returns c-‘0’ */

#endif
