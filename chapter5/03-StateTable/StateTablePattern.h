#ifndef StateTablePattern_H
#define StateTablePattern_H

typedef enum TSTATETYPE {
    NULL_STATE,
    NONUMBER_STATE,
    GN_PROCESSINGWHOLEPART_STATE,
    GN_PROCESSINGFRACTIONALPART_STATE
} TSTATETYPE;

/* This action pointer accepts the me object pointer and no other parameters.  */
typedef void (*ActionPtr0)(void*);

/* This action pointer accepts the me object pointer and the passed character. This means that the client must always send the character data with the event.  */
typedef void (*ActionPtr1)(void*, char);

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

typedef struct ap {
    int nParams; /* 0 or 1 in this case */
    union {
        ActionPtr0 a0;
        ActionPtr1 a1;
    } aPtr;
} ActionType;

typedef ActionType* ActionPtr;
/* This function returns a int that is treated as a boolean (0 == FALSE) and, if present, is used to determine whether or not the transition is taken. Note that this function takes no paramaeters (other than the object me pointer).  */
typedef int (*GuardType)(void *);


typedef struct TableEntryType {
    ActionPtr entryActionPtr;
    ActionPtr exitActionPtr;
    GuardType guardPtr;
    TSTATETYPE newState;
    ActionPtr transActionPtr;
} TableEntryType;

/* digit returns an int value of the char
   That is: return c-'0' */
int digit(char c);

#endif
