#ifndef CRRobotArmManager_H
#define CRRobotArmManager_H

#include <stdio.h>
#include <stdlib.h>

struct CRDisplay;
struct RobotArm;
struct UserInput;

typedef struct CRRobotArmManager CRRobotArmManager;
struct CRRobotArmManager {
    struct CRDisplay* itsCRDisplay;
    struct RobotArm* itsRobotArm;
    struct UserInput* itsUserInput;
};


/* Constructors and destructors:*/

void CRRobotArmManager_Init(CRRobotArmManager* const me);
void CRRobotArmManager_Cleanup(CRRobotArmManager* const me);

/* Operations */
void CRRobotArmManager_motorZero(CRRobotArmManager* const me);
void CRRobotArmManager_moveRobotArm(CRRobotArmManager* const me);
struct CRDisplay* CRRobotArmManager_getItsCRDisplay(const CRRobotArmManager* const me);

void CRRobotArmManager_setItsCRDisplay(CRRobotArmManager* const me, struct CRDisplay* p_CRDisplay);

struct RobotArm* CRRobotArmManager_getItsRobotArm(const CRRobotArmManager* const me);

void CRRobotArmManager_setItsRobotArm(CRRobotArmManager* const me, struct RobotArm* p_RobotArm);

struct UserInput* CRRobotArmManager_getItsUserInput(const CRRobotArmManager* const me);

void CRRobotArmManager_setItsUserInput(CRRobotArmManager* const me, struct UserInput* p_UserInput);

CRRobotArmManager * CRRobotArmManager_Create(void);

void CRRobotArmManager_Destroy(CRRobotArmManager* const me);

#endif
