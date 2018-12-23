#include "Action.h"
#include <stdlib.h>

void Action_Init(Action* me){
}
void Action_Cleanup(Action* me){

}

Action* Action_Create(){
    Action* me = (Action*)malloc(sizeof(Action));
    if (me != NULL)
    {
        Action_Init(me);
    }
    return me;
}
void Action_Destroy(Action* me){
    if (me != NULL)
    {
        Action_Destroy(me);
    }
    free(me);
}
