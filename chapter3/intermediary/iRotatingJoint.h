#ifndef IRoatingJoint_H
#define IRoatingJoint_H

typedef struct iRoatingJoint iRoatingJoint;
struct iRoatingJoint
{
    int (*getRotation)();
    int (*rotate)(int x);
    int (*zero)();
};


#endif
