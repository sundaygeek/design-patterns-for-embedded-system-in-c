#include "MotorData.h"
#include <stdlib.h>
#include "MotorController.h"

static int mc_priority = 8;
static int mc_eventQueue[10];
static int mc_stack[1024];

int motor1Pos;
int motor2Pos;

void MotorController_Init(void) {
    /* use a queue of 10 events, and a 1024 element stack */
    /* create the OS event queue and the task */
    OSQCreate (&mc_eventQueue[0], 10);
    OSTaskCreate (MotorController_run,  NULL, (void *)&mc_stack[1024], 5);

    /* now run the task */
    MotorController_run();
}

void MotorController_Cleanup(void) {
}

void MotorController_run(void) {
    int os_pend_timer_id, x, y;
    os_pend_timer_id = OSCreateTimer(100, RETRIGGER);

    while (TRUE) {
        OSQPend(os_pend_timer_id, WAIT_FOREVER);;
        move();
        };
}

void move(void) {
    int m1Pos, m2Pos;
    /* this function would read the instrument
       panel to set the motor movement settings
       to set the position of the motors.
       Note that if you want to set only one
       of the motors, then set a negative value
       for the commanded position of the other
    */
    m1Pos = rand();
    m2Pos = rand();

    if (m1Pos >= 0)
        motor1Pos = m1Pos;
    if (m2Pos >=0)
        motor2Pos = m2Pos;
    setCmdPos(100*m1Pos + m2Pos);
}

void zero(void) {
    motor1Pos = 0;
    motor2Pos = 0;
    setCmdPos(0);
}

void MotorController_initRelations(void) {
    MotorController_Init();
}
