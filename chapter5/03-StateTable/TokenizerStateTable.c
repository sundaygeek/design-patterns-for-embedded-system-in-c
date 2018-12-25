#include "TokenizerStateTable.h"
#include "Mutex.h"
static void cleanUpRelations(TokenizerStateTable* const me);

void TokenizerStateTable_Init(TokenizerStateTable* const me) {
    me->ch = 'x';
    me->result = 0.0;
    me->tensPlace = 10.0;
    me->itsMutex = NULL;
    TSTATETYPE st;
    EventType ev;
    TableEntryType te;

    /* initialize each cell of the table to null condition */
    for (st=NULL_STATE; st<=GN_PROCESSINGFRACTIONALPART_STATE; st++) {
        for (ev=EVDIGIT; ev<=EVENDOFSTRING; ev++) {
            me->table[st][ev].newState = NULL_STATE;
        me->table[st][ev].guardPtr = (GuardType)NULL;
        me->table[st][ev].exitActionPtr = NULL;
        me->table[st][ev].transActionPtr = NULL;
        me->table[st][ev].entryActionPtr = NULL;
        }
      }

     /*                                   */
     /* now add the specific transitions */
     /*                                   */
     /* evDigit from NoNumber to ProcessingWholePart */
     te.guardPtr = (GuardType)NULL;
     te.exitActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.exitActionPtr->nParams = 0;
     te.exitActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_exit_NoNumber;
     te.transActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.transActionPtr->nParams = 1;
     te.transActionPtr->aPtr.a1 = (ActionPtr1)TokenizerStateTable_NoNum2GN;
     te.entryActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.entryActionPtr->nParams = 0;
     te.entryActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_enter_ProcessingWholePart;
     te.newState = GN_PROCESSINGWHOLEPART_STATE;
     me->table[NONUMBER_STATE][EVDIGIT] = te;

     /* evDigit from Proessing Whole Part to itself */
     te.guardPtr = (GuardType)NULL;
     te.exitActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.exitActionPtr->nParams = 0;
     te.exitActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_exit_NoNumber;
     te.transActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.transActionPtr->nParams = 1;
     te.transActionPtr->aPtr.a1 = (ActionPtr1)TokenizerStateTable_assignCh;
     te.entryActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.entryActionPtr->nParams = 0;
     te.entryActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_enter_ProcessingWholePart;
     te.newState = GN_PROCESSINGWHOLEPART_STATE;
     me->table[GN_PROCESSINGWHOLEPART_STATE][EVDIGIT] = te;

     /* evDot from NoNumber to ProcessingFractionalPart */
     te.guardPtr = (GuardType)NULL;
     te.exitActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.exitActionPtr->nParams = 0;
     te.exitActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_exit_NoNumber;
     te.transActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.transActionPtr->nParams = 1;
     te.transActionPtr->aPtr.a1 = (ActionPtr1)TokenizerStateTable_NoNum2GN;
     te.entryActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.entryActionPtr->nParams = 0;
     te.entryActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_enter_ProcessingFractionalPart;
     te.newState = GN_PROCESSINGFRACTIONALPART_STATE;
     me->table[NONUMBER_STATE][EVDOT] = te;

     /* evDot from ProcessingWholePart to ProcessingFractionalPart */
     te.guardPtr = (GuardType)NULL;
     te.exitActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.exitActionPtr->nParams = 0;
     te.exitActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_exit_ProcessingWholePart;
     te.transActionPtr = (ActionPtr)NULL;
     te.entryActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.entryActionPtr->nParams = 0;
     te.entryActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_enter_ProcessingFractionalPart;
     te.newState = GN_PROCESSINGFRACTIONALPART_STATE;
     me->table[GN_PROCESSINGWHOLEPART_STATE][EVDOT] = te;

     /* evDigit from ProcessingFractionalPart to ProcessingFractionalPart */
     te.guardPtr = (GuardType)NULL;
     te.exitActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.exitActionPtr->nParams = 0;
     te.exitActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_exit_ProcessingFractionalPart;
     te.transActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.transActionPtr->nParams = 1;
     te.transActionPtr->aPtr.a1 = (ActionPtr1)TokenizerStateTable_Frac2Frac;
     te.entryActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.entryActionPtr->nParams = 0;
     te.entryActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_enter_ProcessingFractionalPart;
     te.newState = GN_PROCESSINGFRACTIONALPART_STATE;
     me->table[GN_PROCESSINGFRACTIONALPART_STATE][EVDIGIT] = te;

     /* evWhiteSpace from ProcessingWholePart to NoNumber */
     te.guardPtr = (GuardType)NULL;
     te.exitActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.exitActionPtr->nParams = 0;
     te.exitActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_exit_ProcessingWholePart;
     te.transActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.transActionPtr->nParams = 0;
     te.transActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_printResult;
     te.entryActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.entryActionPtr->nParams = 0;
     te.entryActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_enter_NoNumber;
     te.newState = NONUMBER_STATE;
     me->table[GN_PROCESSINGWHOLEPART_STATE][EVWHITESPACE] = te;

     /* evWhiteSpace from ProcessingFractionalPart to NoNumber */
     te.guardPtr = (GuardType)NULL;
     te.exitActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.exitActionPtr->nParams = 0;
     te.exitActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_exit_ProcessingFractionalPart;
     te.transActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.transActionPtr->nParams = 0;
     te.transActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_printResult;
     te.entryActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.entryActionPtr->nParams = 0;
     te.entryActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_enter_NoNumber;
     te.newState = NONUMBER_STATE;
     me->table[GN_PROCESSINGFRACTIONALPART_STATE][EVWHITESPACE] = te;

     /* evEndOfString from ProcessingWholePart to NoNumber */
     te.guardPtr = (GuardType)NULL;
     te.exitActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.exitActionPtr->nParams = 0;
     te.exitActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_exit_ProcessingWholePart;
     te.transActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.transActionPtr->nParams = 0;
     te.transActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_printResult;
     te.entryActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.entryActionPtr->nParams = 0;
     te.entryActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_enter_NoNumber;
     te.newState = NONUMBER_STATE;
     me->table[GN_PROCESSINGWHOLEPART_STATE][EVENDOFSTRING] = te;

     /* evEndOfString from ProcessingFractionalPart to NoNumber */
     te.guardPtr = (GuardType)NULL;
     te.exitActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.exitActionPtr->nParams = 0;
     te.exitActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_exit_ProcessingFractionalPart;
     te.transActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.transActionPtr->nParams = 0;
     te.transActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_printResult;
     te.entryActionPtr = (ActionPtr)malloc(sizeof(ActionPtr));
     te.entryActionPtr->nParams = 0;
     te.entryActionPtr->aPtr.a0 = (ActionPtr0)TokenizerStateTable_enter_NoNumber;
     te.newState = NONUMBER_STATE;
     me->table[GN_PROCESSINGFRACTIONALPART_STATE][EVENDOFSTRING] = te;

     /* Last initialization activity - enter the initial state */
     me->stateID = NONUMBER_STATE;
     TokenizerStateTable_enter_NoNumber(me);
}

void TokenizerStateTable_Cleanup(TokenizerStateTable* const me) {
    cleanUpRelations(me);
}

void TokenizerStateTable_eventDispatch(TokenizerStateTable* const me, Event e) {
    int takeTransition = 0;
    Mutex_lock(me->itsMutex);
    /* first ensure the entry is within the table boundaries */
    if (me->stateID >= NULL_STATE && me->stateID <= GN_PROCESSINGFRACTIONALPART_STATE) {
        if (e.eType >= EVDIGIT && e.eType <= EVENDOFSTRING) {
            /* is there a valid transition for the current state and event? */
            if (me->table[me->stateID][e.eType].newState != NULL_STATE) {
                /* is there a guard? */
                if (me->table[me->stateID][e.eType].guardPtr == NULL)
                    /* is the guard TRUE? */
                    takeTransition = TRUE; /* if no guard, then it "evaluates" to TRUE */
                else
                    takeTransition =(me->table[me->stateID][e.eType].guardPtr(me));
                if (takeTransition) {
                    if (me->table[me->stateID][e.eType].exitActionPtr != NULL)
                        if (me->table[me->stateID][e.eType].exitActionPtr->nParams == 0)
                            me->table[me->stateID][e.eType].exitActionPtr->aPtr.a0(me);
                        else
                            me->table[me->stateID][e.eType].exitActionPtr->aPtr.a1(me, e.ed.c);
                    if (me->table[me->stateID][e.eType].transActionPtr != NULL)
                        if (me->table[me->stateID][e.eType].transActionPtr->nParams == 0)
                            me->table[me->stateID][e.eType].transActionPtr->aPtr.a0(me);
                        else
                            me->table[me->stateID][e.eType].transActionPtr->aPtr.a1(me, e.ed.c);
                    if (me->table[me->stateID][e.eType].entryActionPtr != NULL)
                        if (me->table[me->stateID][e.eType].entryActionPtr->nParams == 0)
                            me->table[me->stateID][e.eType].entryActionPtr->aPtr.a0(me);
                        else
                           me->table[me->stateID][e.eType].entryActionPtr->aPtr.a1(me, e.ed.c);
                    me->stateID = me->table[me->stateID][e.eType].newState;
                }
            }
        }
    }
    Mutex_release(me->itsMutex);
}

void TokenizerStateTable_enter_GotNumber(TokenizerStateTable* const me) {
    me->tensPlace = 10.0;
}

void TokenizerStateTable_enter_NoNumber(TokenizerStateTable* const me) {
    me->result = 0.0;
}

void TokenizerStateTable_enter_ProcessingFractionalPart(TokenizerStateTable* const me) {

}

void TokenizerStateTable_enter_ProcessingWholePart(TokenizerStateTable* const me) {
    me->result = me->result*10 + digit(me->ch);
}

void TokenizerStateTable_exit_GotNumber(TokenizerStateTable* const me) {

}

void TokenizerStateTable_exit_NoNumber(TokenizerStateTable* const me) {

}

void TokenizerStateTable_exit_ProcessingFractionalPart(TokenizerStateTable* const me) {

}

void TokenizerStateTable_exit_ProcessingWholePart(TokenizerStateTable* const me) {

}

struct Mutex* TokenizerStateTable_getItsMutex(const TokenizerStateTable* const me) {
    return (struct Mutex*)me->itsMutex;
}

void TokenizerStateTable_setItsMutex(TokenizerStateTable* const me, struct Mutex* p_Mutex) {
    me->itsMutex = p_Mutex;
}

TokenizerStateTable * TokenizerStateTable_Create(void) {
    TokenizerStateTable* me = (TokenizerStateTable *) malloc(sizeof(TokenizerStateTable));
    if(me!=NULL)
        TokenizerStateTable_Init(me);
    return me;
}

void TokenizerStateTable_Destroy(TokenizerStateTable* const me) {
    if(me!=NULL)
        TokenizerStateTable_Cleanup(me);
    free(me);
}

static void cleanUpRelations(TokenizerStateTable* const me) {
    if(me->itsMutex != NULL)
            me->itsMutex = NULL;
}

void TokenizerStateTable_assignCh(TokenizerStateTable* const me, char c) {
    me->ch = c;
}

void TokenizerStateTable_NoNum2GN(TokenizerStateTable* const me, char c) {
    TokenizerStateTable_assignCh(me, c);
    me->tensPlace = 10.0;
}

void TokenizerStateTable_Frac2Frac(TokenizerStateTable* const me, char c) {
    me->ch = c;
    me->result += digit(me->ch)/me->tensPlace;
    me->tensPlace *= 10;
}

void TokenizerStateTable_printResult(TokenizerStateTable* const me) {
    printf("Number: %g\n", me->result);
}
