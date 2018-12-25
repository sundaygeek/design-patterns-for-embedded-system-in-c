#ifndef TokenizeAsyncSingle_H
#define TokenizeAsyncSingle_H

/* this is the size of the event queue */
#define QSIZE 100

typedef enum EventType {
    EVDIGIT,
    EVDOT,
    EVWHITESPACE,
    EVENDOFSTRING
} EventType;

typedef struct {
    EventType eType;
    union eventData {
        char c;
        } ed;
} Event;

typedef enum TSTATETYPE {
    NULL_STATE,
    NONUMBER_STATE,
    GOTNUMBER_STATE
} TSTATETYPE;

typedef enum TSUBSTATETYPE {
    NULL_SSTATE,
    PROCESSINGWHOLEPART_SSTATE,
    PROCESSINGFRACTIONALPART_SSTATE
} TSUBSTATETYPE;


/* helper function returns the digit */
/* held by a char */
int digit(char c) {
    return c-'0';
    }

/*
  OS signal and wait functions for
  task synchronization
*/
void postSignal(void);
void waitOnSignal(void);

#endif
