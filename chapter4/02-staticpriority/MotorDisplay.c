#include "MotorData.h"
#include <stdio.h>
#include "MotorDisplay.h"

static int md_priority = 10;
static int md_eventQueue[10];
static int md_stack[1024];

void MotorDisplay_Init(void) {
    /* create the OS event queue and the task */
    /* use a queue of 10 events, and a 1024 element stack */
    OSQCreate (&md_eventQueue[0], 10);
    OSTaskCreate (MotorDisplay_run,  NULL, (void *)&md_stack[1024], 5);

    /* now run the task */
    MotorDisplay_run();
}

void MotorDisplay_Cleanup(void) {
}

void MotorDisplay_run(void) {
    int os_pend_timer_id;
    os_pend_timer_id = OSCreateTimer(500, RETRIGGER);

    while (TRUE) {
        OSQPend(os_pend_timer_id, WAIT_FOREVER);
        display();
        };
}

void display(void) {
    printf("Commanded position = %d\n", getCmdPos());
    printf("Measured position  = %d\n\n", getMeasPos());
}

void MotorDisplay_initRelations(void) {
    MotorDisplay_Init();
}
