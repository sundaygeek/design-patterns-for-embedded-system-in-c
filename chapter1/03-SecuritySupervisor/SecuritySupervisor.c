#include "SecuritySupervisor.h"
#include <string.h>
#include <stdio.h>

static char pin[4];

void displayMsg(char* msg){
    printf("%s\n", msg);
}

int isCancel(char key){
    return key == ESC_KEY;
}

int isDigit(char key){
    return ((key) >= '0' && (key) <= '9');
}

int isEnter(char key){
    return key == ENTER_KEY;
}

int isReset(char key){
    return key == RESET_KEY;
}

void addKey(char key){
    int i;
    for (i = 0; i < 4; ++i)
    {
        if(pin[i] != 0)
            break;
    }
    pin[i] = key;
}

int isValid(char* pin){
    return strcmp(pin, "1234");
}

void unlockDoor(){

}

void lockDoor(){

}

EventStatus dispatchEvent(DoorMachineState* door){
    Param* params = door->params;
    char id = door->id;
    EventStatus res = EventNotConsumed;

    printf("%d\n", door->activeState);
    printf("%s\n", pin);

    switch(door->activeState){
        case SecuritySupervisor_Idle:
            {
                if (id == Null_id)  //not trigger event
                {
                    door->activeState = SecuritySupervisor_ErrorState;
                    displayMsg("ERROR: max retries exceeded");
                    res = EventConsumed;
                }
                else
                {
                    ++door->retries;
                    door->activeState = SecuritySupervisor_Accepting;
                    res = EventConsumed;
                }
            }
            break;
        case SecuritySupervisor_Accepting:
            {
                if (id == keypress_SecuritySupervisor_Event_id)
                {
                    if (isCancel(params->key))
                    {
                        door->retries = 0;
                        displayMsg("Canceled");
                        door->activeState = SecuritySupervisor_Idle;
                        strcpy(pin, "");
                    }
                    else
                    {
                        if(isDigit(params->key)){
                            addKey(params->key);
                            door->activeState = SecuritySupervisor_Accepting;
                            res = EventConsumed;
                        }
                        else
                        {
                            if (isEnter(params->key))
                            {
                                door->activeState = SecuritySupervisor_CheckingLength;
                                res = EventConsumed;
                            }
                        }
                    }
                }
            }
            break;
        case SecuritySupervisor_CheckingLength:
            if (id == Null_id)
            {
                if (strlen(pin) == 4)
                {
                    door->activeState = SecuritySupervisor_ValidatingPIN;
                    res = EventConsumed;
                }
                else
                {
                    displayMsg("ERROR: wrong PIN length");
                    door->activeState = SecuritySupervisor_Idle;
                    strcpy(pin, "");
                    res = EventConsumed;
                }
            }
            break;
        case SecuritySupervisor_ValidatingPIN:
            if (id == Null_id)
            {
                if (isValid(pin))
                {
                    unlockDoor();
                    displayMsg("Door unlocked");
                    door->activeState = SecuritySupervisor_SecurityOpen;
                    res = EventConsumed;
                }
                else
                {
                    displayMsg("ERROR: invalid PIN");
                    door->activeState = SecuritySupervisor_Idle;
                    strcpy(pin, "");
                    res = EventConsumed;
                }
            }
            break;
        case SecuritySupervisor_SecurityOpen:
            if (id == keypress_SecuritySupervisor_Event_id)
            {
                if (isReset(params->key))
                {
                    lockDoor();
                    displayMsg("Door locked");
                    door->activeState = SecuritySupervisor_Idle;
                    strcpy(pin, "");
                    res = EventConsumed;
                }
            }
            break;
        default:
            break;
    }
    return res;
}
