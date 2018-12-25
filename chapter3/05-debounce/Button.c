#include "Button.h"

void Button_Init(Button* const me){
    me->deviceState = 0;
}
void Button_Cleanup(Button* const me){

}

Button* Button_Create(){
    Button* me = (Button*)malloc(sizeof(Button));
    if (me != NULL)
    {
        Button_Init(me);
    }
    return me;
}

void Button_Destroy(Button* const me){
    if (me != NULL)
    {
        Button_Cleanup(me);
    }
    free(me);
}

void Button_backlight(Button* const me, int backlight){
    me->backlight = backlight;
}

int Button_getState(Button* const me){
    return me->deviceState;
}

void Button_setItsButtonDriver(Button* const me, ButtonDriver* const buttonDriver){
    me->buttonDriver = buttonDriver;
}

ButtonDriver* Button_getItsButtonDriver(Button* const me){
    return me->buttonDriver;
}
