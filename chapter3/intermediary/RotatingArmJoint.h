#ifndef RotatingArmJoint_H
#define RotatingArmJoint_H

typedef struct RotatingArmJoint RotatingArmJoint;
struct RotatingArmJoint
{
    int angle;
    char deviceID;
};

int RotatingArmJoint_getRotation(RotatingArmJoint* const me);
int RotatingArmJoint_rotate(RotatingArmJoint* const me, int x);
int RotatingArmJoint_zero(RotatingArmJoint* const me);

#endif
