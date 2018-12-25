#ifndef BUTTON_H
#define BUTTON_H

#include "ButtonDriver.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Button Button;
struct Button
{
    int deviceState;
    int backlight;
    ButtonDriver* buttonDriver;
};

void Button_Init(Button* const me);
void Button_Cleanup(Button* const me);

Button* Button_Create();
void Button_Destroy(Button* const me);

void Button_backlight(Button* const me, int light);
int Button_getState(Button* const me);
void Button_setItsButtonDriver(Button* const me, ButtonDriver* const buttonDriver);
ButtonDriver* Button_getItsButtonDriver(Button* const me);

#endif
