#ifndef SecuritySupervisor_H
#define SecuritySupervisor_H

#define Null_id 0
#define keypress_SecuritySupervisor_Event_id 1

#define ESC_KEY 'c'
#define ENTER_KEY 'e'
#define RESET_KEY 'r'

typedef enum ActiveState
{
    SecuritySupervisor_Idle,
    SecuritySupervisor_Accepting,
    SecuritySupervisor_CheckingLength,
    SecuritySupervisor_ValidatingPIN,
    SecuritySupervisor_SecurityOpen,
    SecuritySupervisor_ErrorState
} ActiveState;

typedef enum EventStatus
{
    EventNotConsumed,
    EventConsumed
} EventStatus;

typedef struct Param Param;
struct Param
{
    int key;
};

typedef struct DoorMachineState DoorMachineState;
struct DoorMachineState
{
    Param* params;
    ActiveState activeState;
    int retries;
    char id;
};


void displayMsg(char* msg);
EventStatus dispatchEvent(DoorMachineState* door);
int isDigit(char key);
int isEnter(char key);
int isValid(char* pin);
int isCancel(char key);
int isReset(char key);
void unlockDoor();
void lockDoor();

#endif //SecuritySupervisor_H
