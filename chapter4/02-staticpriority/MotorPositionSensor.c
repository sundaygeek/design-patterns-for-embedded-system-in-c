#include "MotorData.h"
#include "MotorPositionSensor.h"
#include <stdlib.h>

static int mps_priority = 5;
static int mps_eventQueue[10];
static int mps_stack[1024];

void MotorPositionSensor_Cleanup(void) {
}
void MotorPositionSensor_Init(void) {
    /* create the OS event queue and the task */
    /* use a queue of 10 events, and a 1024 element stack */
    OSQCreate(&mps_eventQueue[0], 10);
    OSTaskCreate(MotorPositionSensor_run,  NULL, (void *)&mps_stack[1024], 5);

    /* now run the task */
    MotorPositionSensor_run();
}

void MotorPositionSensor_run(void) {
    int os_pend_timer_id;
    os_pend_timer_id = OSCreateTimer(50, RETRIGGER);

    while (TRUE) {
        OSQPend(os_pend_timer_id, WAIT_FOREVER);
        getPosition();
    };
}

void getPosition(void) {
    int x;
    /* get position by reading the sensor */
    x = rand();
    setMeasPos(x);
}

void MotorPositionSensor_initRelations(void) {
    MotorPositionSensor_Init();
}
