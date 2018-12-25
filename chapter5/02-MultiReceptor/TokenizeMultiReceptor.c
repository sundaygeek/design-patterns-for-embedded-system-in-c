#include "TokenizerMultiReceptor.h"
#include "Mutex.h"

static void cleanUpRelations(TokenizerMultiReceptor* const me);

void TokenizerMultiReceptor_Cleanup(TokenizerMultiReceptor* const me) {
    cleanUpRelations(me);
}

/*
    process the evDigit event, passing the character
    c as a parameter
*/
void TokenizerMultiReceptor_evDigit(TokenizerMultiReceptor* const me, char c) {
    Mutex_lock(me->itsMutex);
    switch (me->stateID) {
        case NONUMBER_STATE:
            /* transition to GotNumber state, default substate */
            TokenizerMultiReceptor_exit_NoNumber(me);
            me->ch = c;
            TokenizerMultiReceptor_enter_GotNumber(me);
            me->stateID = GOTNUMBER_STATE;
            TokenizerMultiReceptor_enter_ProcessingWholePart(me);
            me->subStateID = PROCESSINGWHOLEPART_SSTATE;
            printf("Current value of result: %g\n", me->result);
            break;
        case GOTNUMBER_STATE:
            switch (me->subStateID) {
                case PROCESSINGWHOLEPART_SSTATE:
                     TokenizerMultiReceptor_exit_ProcessingWholePart(me);
                     me->ch = c;
                     TokenizerMultiReceptor_enter_ProcessingWholePart(me);
                     printf("Current value of result: %g\n", me->result);
                     break;
                case PROCESSINGFRACTIONALPART_SSTATE:
                     TokenizerMultiReceptor_exit_ProcessingFractionalPart(me);
                     me->ch = c;
                     me->result += digit(me->ch) / me->tensPlace;
                     me->tensPlace *= 10.0;
                     TokenizerMultiReceptor_enter_ProcessingFractionalPart(me);
                     printf("Current value of result: %g\n", me->result);
                     break;
                };
            };
    Mutex_release(me->itsMutex);
}

/*
    process the evDot
*/
void TokenizerMultiReceptor_evDot(TokenizerMultiReceptor* const me) {
    Mutex_lock(me->itsMutex);
    me->ch = '.';
    switch (me->stateID) {
        case NONUMBER_STATE:
            /* transition to GotNumber state, default substate */
            TokenizerMultiReceptor_exit_NoNumber(me);
            TokenizerMultiReceptor_enter_GotNumber(me);
            me->stateID = GOTNUMBER_STATE;
            TokenizerMultiReceptor_enter_ProcessingFractionalPart(me);
            me->subStateID = PROCESSINGFRACTIONALPART_SSTATE;
            break;
        case GOTNUMBER_STATE:
            switch (me->subStateID) {
                case PROCESSINGWHOLEPART_SSTATE:
                     TokenizerMultiReceptor_exit_ProcessingWholePart(me);
                     TokenizerMultiReceptor_enter_ProcessingFractionalPart(me);
                     me->subStateID = PROCESSINGFRACTIONALPART_SSTATE;
                     break;
                };
        };
    Mutex_release(me->itsMutex);
}

/*
    process the evEndOfString event
*/
void TokenizerMultiReceptor_evEndOfString(TokenizerMultiReceptor* const me) {
    Mutex_lock(me->itsMutex);
    switch (me->stateID) {
        case GOTNUMBER_STATE:
            switch (me->subStateID) {
                case PROCESSINGWHOLEPART_SSTATE:
                    TokenizerMultiReceptor_exit_ProcessingWholePart(me);
                    break;
                case PROCESSINGFRACTIONALPART_SSTATE:
                    TokenizerMultiReceptor_exit_ProcessingFractionalPart(me);
                    break;
                };
            TokenizerMultiReceptor_exit_GotNumber(me);
            printf("Number: %g\n", me->result);
            TokenizerMultiReceptor_enter_NoNumber(me);
            me->stateID = NONUMBER_STATE;
            break;
        };
    Mutex_release(me->itsMutex);
}

/*
    process the evWhiteSpace event
*/
void TokenizerMultiReceptor_evWhiteSpace(TokenizerMultiReceptor* const me) {
    Mutex_lock(me->itsMutex);
    switch (me->stateID) {
        case GOTNUMBER_STATE:
            switch (me->subStateID) {
                case PROCESSINGWHOLEPART_SSTATE:
                    TokenizerMultiReceptor_exit_ProcessingWholePart(me);
                    break;
                case PROCESSINGFRACTIONALPART_SSTATE:
                    TokenizerMultiReceptor_exit_ProcessingFractionalPart(me);
                    break;
                };
            TokenizerMultiReceptor_exit_GotNumber(me);
            printf("Number: %g\n", me->result);
            TokenizerMultiReceptor_enter_NoNumber(me);
            me->stateID = NONUMBER_STATE;
            break;
        };
    Mutex_release(me->itsMutex);
}

/*
    entry and exit actions for each state
*/
void TokenizerMultiReceptor_enter_GotNumber(TokenizerMultiReceptor* const me) {
    me->tensPlace = 10.0;
}

void TokenizerMultiReceptor_enter_NoNumber(TokenizerMultiReceptor* const me) {
    me->result = 0.0;
}

void TokenizerMultiReceptor_enter_ProcessingFractionalPart(TokenizerMultiReceptor* const me) {

}

void TokenizerMultiReceptor_enter_ProcessingWholePart(TokenizerMultiReceptor* const me) {
    me->result = me->result*10 + digit(me->ch);
}

void TokenizerMultiReceptor_exit_GotNumber(TokenizerMultiReceptor* const me) {
    me->subStateID = NULL_SSTATE;
}

void TokenizerMultiReceptor_exit_NoNumber(TokenizerMultiReceptor* const me) {

}

void TokenizerMultiReceptor_exit_ProcessingFractionalPart(TokenizerMultiReceptor* const me) {

}

void TokenizerMultiReceptor_exit_ProcessingWholePart(TokenizerMultiReceptor* const me) {

}

/* helper functions */
TokenizerMultiReceptor * TokenizerMultiReceptor_Create(void) {
    TokenizerMultiReceptor* me = (TokenizerMultiReceptor *) malloc(sizeof(TokenizerMultiReceptor));
    if(me!=NULL)
        TokenizerMultiReceptor_Init(me);
    return me;
}

void TokenizerMultiReceptor_Destroy(TokenizerMultiReceptor* const me) {
    if(me!=NULL)
            TokenizerMultiReceptor_Cleanup(me);
    free(me);
}


void TokenizerMultiReceptor_Init(TokenizerMultiReceptor* const me) {
    me->ch = 'x';
    me->result = 0.0;
    me->tensPlace = 10.0;
    me->itsMutex = NULL;

    /* initialize state variables */
          me->stateID = NONUMBER_STATE;
    me->subStateID = NULL_SSTATE;
}

struct Mutex* TokenizerMultiReceptor_getItsMutex(const TokenizerMultiReceptor* const me) {
    return (struct Mutex*)me->itsMutex;
}

void TokenizerMultiReceptor_setItsMutex(TokenizerMultiReceptor* const me, struct Mutex* p_Mutex) {
    me->itsMutex = p_Mutex;
}

static void cleanUpRelations(TokenizerMultiReceptor* const me) {
    if(me->itsMutex != NULL)
            me->itsMutex = NULL;
}
