#include <stdio.h>
#include "RobotArmManager.h"
#include "Action.h"

int main(int argc, char const *argv[])
{
    int x,y,z,t;

    RobotArmManager* me = RobotArmManager_Create();
    x=1;
    y=2;
    z=3;
    t=4;
    RobotArmManager_computeTrajectory(me, x, y, z, t);
    x=5;
    y=6;
    z=7;
    t=8;
    RobotArmManager_graspAt(me, x, y, z, t);
    // struct Action
    // {
    //     int rotatingArmJoint1;
    //     int rotatingArmJoint2;
    //     int rotatingArmJoint3;
    //     int rotatingArmJoint4;
    //     int slidingArmJoint1;
    //     int slidingArmJoint2;
    //     int manipulatorForce;
    //     int manipulatorOpen;
    // };
    Action* action = (Action*)malloc(sizeof(Action));
    action->rotatingArmJoint1 = 11;
    action->rotatingArmJoint2 = 11;
    action->rotatingArmJoint3 = 11;
    action->rotatingArmJoint4 = 11;
    action->slidingArmJoint1 = 11;
    action->slidingArmJoint2 = 11;
    action->manipulatorForce = 11;
    action->manipulatorOpen = 11;
    RobotArmManager_addItsAction(me, action);

    RotatingArmJoint* p_RotatingArmJoint = (RotatingArmJoint*)malloc(sizeof(RotatingArmJoint));
    RobotArmManager_addItsRotatingArmJoint(me, p_RotatingArmJoint);

    RobotArmManager_executeStep(me);

    RobotArmManager_Destroy(me);
    return 0;
}
