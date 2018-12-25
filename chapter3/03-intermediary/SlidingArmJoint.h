#ifndef SlidingArmJoint_H
#define SlidingArmJoint_H

typedef struct SlidingArmJoint SlidingArmJoint;
struct SlidingArmJoint
{
    int currentLength;
    int deviceID;
    int minArmLength;
    int maxArmLength;
};

int SlidingArmJoint_getLength(SlidingArmJoint*const me);
int SlidingArmJoint_setLength(SlidingArmJoint*const me, int x);
int SlidingArmJoint_zero(SlidingArmJoint*const me);

#endif
