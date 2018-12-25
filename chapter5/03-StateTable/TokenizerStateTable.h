#ifndef TokenizerStateTable_H
#define TokenizerStateTable_H

#include "StateTablePattern.h"
struct Mutex;

typedef struct TokenizerStateTable TokenizerStateTable;
struct TokenizerStateTable {
    char ch;
    double result;
    TSTATETYPE stateID;
    TableEntryType table[GN_PROCESSINGFRACTIONALPART_STATE+1][EVENDOFSTRING+1];
    double tensPlace;
    struct Mutex* itsMutex;
};

/* Constructors and destructors:*/
void TokenizerStateTable_Init(TokenizerStateTable* const me);

void TokenizerStateTable_Cleanup(TokenizerStateTable* const me);

/* Operations */
void TokenizerStateTable_eventDispatch(TokenizerStateTable* const me, Event e);

void TokenizerStateTable_enter_GotNumber(TokenizerStateTable* const me);

void TokenizerStateTable_enter_NoNumber(TokenizerStateTable* const me);

void TokenizerStateTable_enter_ProcessingFractionalPart(TokenizerStateTable* const me);

void TokenizerStateTable_enter_ProcessingWholePart(TokenizerStateTable* const me);

void TokenizerStateTable_exit_GotNumber(TokenizerStateTable* const me);

void TokenizerStateTable_exit_NoNumber(TokenizerStateTable* const me);

void TokenizerStateTable_exit_ProcessingFractionalPart(TokenizerStateTable* const me);

void TokenizerStateTable_exit_ProcessingWholePart(TokenizerStateTable* const me);

struct Mutex* TokenizerStateTable_getItsMutex(const TokenizerStateTable* const me);

void TokenizerStateTable_setItsMutex(TokenizerStateTable* const me, struct Mutex* p_Mutex);

TokenizerStateTable * TokenizerStateTable_Create(void);

void TokenizerStateTable_Destroy(TokenizerStateTable* const me);

void TokenizerStateTable_assignCh(TokenizerStateTable* const me, char c);

void TokenizerStateTable_NoNum2GN(TokenizerStateTable* const me, char c);

void TokenizerStateTable_Frac2Frac(TokenizerStateTable* const me, char c);

void TokenizerStateTable_printResult(TokenizerStateTable* const me);

#endif
