#ifndef LED_H
#define LED_H

#include <stdio.h>
#include <stdlib.h>
#define LED_ON 1
#define LED_OFF 0

typedef struct LED LED;
struct LED
{
    int LEDStatus;
};

void LED_Init(LED* const me);
void LED_Cleanup(LED* const me);

LED* LED_Create();
void LED_Destroy(LED* const me);

void LED_LightOn(LED* const me);
void LED_LightOff(LED* const me);

#endif
