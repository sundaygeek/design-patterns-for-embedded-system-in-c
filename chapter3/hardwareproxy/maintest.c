#include "MotorProxy.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    MotorProxy * motor = MotorProxy_Create();
    // config rotaryArmLength and motor address
    unsigned int rotaryArmLength = 10;
    unsigned int location = 0x154545454;

    DirectionType direction;
    unsigned int speed;

    MotorProxy_configure(motor, rotaryArmLength, &location);
    MotorProxy_initialize(motor);
    MotorProxy_enable(motor);

    direction = FORWARD;
    speed = 10;
    MotorProxy_writeMotorSpeed(motor, &direction, speed);
    DirectionType* getdirection = MotorProxy_accessMotorDirection(motor);
    unsigned int getspeed = MotorProxy_accessMotorSpeed(motor);
    unsigned int getstate = MotorProxy_aceessMotorState(motor);
    printf("Motor current direction:%d, speed:%d, state:%d\n", getdirection, getspeed, getstate);

    direction = REVERSE;
    speed = 20;
    MotorProxy_writeMotorSpeed(motor, &direction, speed);
    getdirection = MotorProxy_accessMotorDirection(motor);
    getspeed = MotorProxy_accessMotorSpeed(motor);
    getstate = MotorProxy_aceessMotorState(motor);
    printf("Motor current direction:%d, speed:%d, state:%d\n", getdirection, getspeed, getstate);

    MotorProxy_disable(motor);
    getdirection = MotorProxy_accessMotorDirection(motor);
    getspeed = MotorProxy_accessMotorSpeed(motor);
    getstate = MotorProxy_aceessMotorState(motor);
    printf("Motor current direction:%d, speed:%d, state:%d\n", getdirection, getspeed, getstate);

    MotorProxy_Destroy(motor);
    return 0;
}
