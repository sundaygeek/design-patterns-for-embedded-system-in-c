#ifndef GraspingManipulator_H
#define GraspingManipulator_H

typedef struct GraspingManipulator GraspingManipulator;
struct GraspingManipulator
{
    int maxForce;
};

int GraspingManipulator_setMaxForce(GraspingManipulator* const me, int maxForce);
int GraspingManipulator_open(GraspingManipulator* me);
int GraspingManipulator_close(GraspingManipulator* me);

#endif
