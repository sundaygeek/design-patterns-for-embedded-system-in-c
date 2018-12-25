#ifndef RobotArmManager_H
#define RobotArmManager_H

#include "GraspingManipulator.h"
#include "RotatingArmJoint.h"
#include "SlidingArmJoint.h"
#include "Action.h"
#include <stdio.h>
#include <stdlib.h>

/*## class RobotArmManager */
typedef struct RobotArmManager RobotArmManager;
struct RobotArmManager {
    unsigned int currentStep;
    unsigned int nSteps;
    struct GraspingManipulator* itsGraspingManipulator;
    struct RotatingArmJoint *itsRotatingArmJoint[4];
    struct SlidingArmJoint *itsSlidingArmJoint[2];
    struct Action *itsAction[100];
    int status;
};

/* Constructors and destructors:*/
void RobotArmManager_Init(RobotArmManager* const me);
void RobotArmManager_Cleanup(RobotArmManager* const me);

/* Operations */
void RobotArmManager_computeTrajectory(RobotArmManager* const me, int x, int y, int z, int t);
int RobotArmManager_executeStep(RobotArmManager* const me);
int RobotArmManager_graspAt(RobotArmManager* const me, int x, int y, int z, int t);
int RobotArmManager_zero(RobotArmManager* const me);

struct GraspingManipulator* RobotArmManager_getItsGraspingManipulator(const RobotArmManager* const me);
void RobotArmManager_setItsGraspingManipulator(RobotArmManager* const me, struct GraspingManipulator* p_GraspingManipulator);

int RobotArmManager_getItsRotatingArmJoint(const RobotArmManager* const me);
void RobotArmManager_addItsRotatingArmJoint(RobotArmManager* const me, struct RotatingArmJoint * p_RotatingArmJoint);
void RobotArmManager_removeItsRotatingArmJoint(RobotArmManager* const me, struct RotatingArmJoint * p_RotatingArmJoint);
void RobotArmManager_clearItsRotatingArmJoint(RobotArmManager* const me);

int RobotArmManager_getItsSlidingArmJoint(const RobotArmManager* const me);
void RobotArmManager_addItsSlidingArmJoint(RobotArmManager* const me, struct SlidingArmJoint * p_SlidingArmJoint);
void RobotArmManager_removeItsSlidingArmJoint(RobotArmManager* const me, struct SlidingArmJoint * p_SlidingArmJoint);
void RobotArmManager_clearItsSlidingArmJoint(RobotArmManager* const me);

int RobotArmManager_getItsAction(const RobotArmManager* const me);
void RobotArmManager_addItsAction(RobotArmManager* const me, struct Action * p_Action);
void RobotArmManager_removeItsAction(RobotArmManager* const me, struct Action * p_Action);
void RobotArmManager_clearItsAction(RobotArmManager* const me);

RobotArmManager * RobotArmManager_Create(void);
void RobotArmManager_Destroy(RobotArmManager* const me);

#endif
