#include "ButtonDriver.h"
#include "Button.h"
#include "MicrowaveEmitter.h"
#include "Timer.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    ButtonDriver* p_ButtonDriver = ButtonDriver_Create();
    Button* p_Button = Button_Create();
    MicrowaveEmitter* p_MicrowaveEmitter = MicrowaveEmitter_Create();
    Timer* p_Timer = Timer_Create();

    p_ButtonDriver->toggleOn = 0;
    p_ButtonDriver->oldState = 1;
    p_Button->deviceState = 0;

    ButtonDriver_setItsButton(p_ButtonDriver, p_Button);
    ButtonDriver_setItsMicrowaveEmitter(p_ButtonDriver, p_MicrowaveEmitter);
    ButtonDriver_setItsTimer(p_ButtonDriver, p_Timer);
    ButtonDriver_eventReceive(p_ButtonDriver);

    p_ButtonDriver->toggleOn = 1;
    p_ButtonDriver->oldState = 1;
    p_Button->deviceState = 0;

    ButtonDriver_setItsButton(p_ButtonDriver, p_Button);
    ButtonDriver_setItsMicrowaveEmitter(p_ButtonDriver, p_MicrowaveEmitter);
    ButtonDriver_setItsTimer(p_ButtonDriver, p_Timer);
    ButtonDriver_eventReceive(p_ButtonDriver);

    return 0;
}
