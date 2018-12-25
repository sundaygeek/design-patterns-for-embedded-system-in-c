#ifndef Action_H
#define Action_H

#include<stdio.h>

typedef struct Action Action;
struct Action
{
    int rotatingArmJoint1;
    int rotatingArmJoint2;
    int rotatingArmJoint3;
    int rotatingArmJoint4;
    int slidingArmJoint1;
    int slidingArmJoint2;
    int manipulatorForce;
    int manipulatorOpen;
};

void Action_Init(Action* me);
void Action_Cleanup(Action* me);

Action* Action_Create();
void Action_Destroy(Action* me);

#endif
