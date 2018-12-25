#include <stdio.h>
#include "TokenizerSyncSingleReceptorPkg.h"

struct Mutex;

typedef struct TokenizerSyncSingleReceptor TokenizerSyncSingleReceptor;
struct TokenizerSyncSingleReceptor {
    char ch;
    double result;
    TSTATETYPE stateID;
    TSUBSTATETYPE subStateID;
    double tensPlace;
    struct Mutex* itsMutex;
};

void TokenizerSyncSingleReceptor_enter_GotNumber(TokenizerSyncSingleReceptor* const me);

void TokenizerSyncSingleReceptor_enter_NoNumber(TokenizerSyncSingleReceptor* const me);

void TokenizerSyncSingleReceptor_enter_ProcessingFractionalPart(TokenizerSyncSingleReceptor* const me);

void TokenizerSyncSingleReceptor_enter_ProcessingWholePart(TokenizerSyncSingleReceptor* const me);

void TokenizerSyncSingleReceptor_exit_GotNumber(TokenizerSyncSingleReceptor* const me);

void TokenizerSyncSingleReceptor_exit_NoNumber(TokenizerSyncSingleReceptor* const me);

void TokenizerSyncSingleReceptor_exit_ProcessingFractionalPart(TokenizerSyncSingleReceptor* const me);

void TokenizerSyncSingleReceptor_exit_ProcessingWholePart(TokenizerSyncSingleReceptor* const me);

void TokenizerSyncSingleReceptor_Init(TokenizerSyncSingleReceptor* const me);

void TokenizerSyncSingleReceptor_Cleanup(TokenizerSyncSingleReceptor* const me);

void TokenizerSyncSingleReceptor_eventDispatch(TokenizerSyncSingleReceptor* const me, Event e);

struct Mutex* TokenizerSyncSingleReceptor_getItsMutex(const TokenizerSyncSingleReceptor* const me);

void TokenizerSyncSingleReceptor_setItsMutex(TokenizerSyncSingleReceptor* const me, struct Mutex* p_Mutex);


TokenizerSyncSingleReceptor * TokenizerSyncSingleReceptor_Create(void);


void TokenizerSyncSingleReceptor_Destroy(TokenizerSyncSingleReceptor* const me);

#endif
