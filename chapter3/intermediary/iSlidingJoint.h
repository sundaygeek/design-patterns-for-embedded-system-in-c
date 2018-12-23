#ifndef ISlidingJoint_H
#define ISlidingJoint_H

typedef struct iSlidingJoint iSlidingJoint;
struct iSlidingJoint
{
    int (*getLength)();
    void (*setLength)(int x);
    int (*zero)();
};
#endif
