#include <stdio.h>
#include "SecuritySupervisor.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    EventStatus status = EventNotConsumed;

    DoorMachineState* door = (DoorMachineState*)malloc(sizeof(DoorMachineState));
    Param* params = (Param*)malloc(sizeof(Param));

    params->key = '1';
    door->params = params;
    door->retries = 0;
    door->activeState = SecuritySupervisor_Idle;
    door->id = keypress_SecuritySupervisor_Event_id;
    status = dispatchEvent(door);

    params->key = '2';
    door->params = params;
    door->id = keypress_SecuritySupervisor_Event_id;
    status = dispatchEvent(door);

    params->key = '3';
    door->params = params;
    door->id = keypress_SecuritySupervisor_Event_id;
    status = dispatchEvent(door);

    params->key = '4';
    door->params = params;
    door->id = keypress_SecuritySupervisor_Event_id;
    status = dispatchEvent(door);

    params->key = 'e';
    door->params = params;
    door->id = keypress_SecuritySupervisor_Event_id;
    status = dispatchEvent(door);

    // params->key = 'c';
    // door->params = params;
    // door->id = keypress_SecuritySupervisor_Event_id;
    // status = dispatchEvent(door);

    // params->key = 'r';
    // door->params = params;
    // door->id = Null_id;
    // status = dispatchEvent(door);

    return 0;
}
