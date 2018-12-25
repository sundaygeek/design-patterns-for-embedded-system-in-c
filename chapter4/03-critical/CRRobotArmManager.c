#include "CRRobotArmManager.h"
#include "CRDisplay.h"
#include "RobotArm.h"
#include "UserInput.h"

static void cleanUpRelations(CRRobotArmManager* const me);

void CRRobotArmManager_Init(CRRobotArmManager* const me) {
    me->itsCRDisplay = NULL;
    me->itsRobotArm = NULL;
    me->itsUserInput = NULL;
}

void CRRobotArmManager_Cleanup(CRRobotArmManager* const me) {
    cleanUpRelations(me);
}

void CRRobotArmManager_motorZero(CRRobotArmManager* const me) {
    int success = 1;
    OS_disable_task_switching();

    /* critical region code */
    success = RobotArm_moveTo(me->itsRobotArm,0,0,0);

    /* critical region ends */
    OS_enable_task_switching();

    if (!success)
        CRDisplay_printMsg(me->itsCRDisplay,"Cannot zero!");
}

void CRRobotArmManager_moveRobotArm(CRRobotArmManager* const me) {
    /* local stack variable declarations */
    int x, y, z, success=1;
    /*non-critical region code */

    /* note that the function below has its
       own critical region and so cannot be
       called inside of the critical region
       of this function
    */
    CRRobotArmManager_motorZero(me);

    x = UserInput_getX(me->itsUserInput);
    y = UserInput_getY(me->itsUserInput);
    z = UserInput_getX(me->itsUserInput);

    /* critical region begins */
    OS_disable_task_switching();

    /* critical region code */
    success = RobotArm_moveTo(me->itsRobotArm,x,y,z);

    /* critical region ends */
    OS_enable_task_switching();

    /* more non-critical region code */
    CRDisplay_printInt(me->itsCRDisplay, "Result is ", success);
}

struct CRDisplay* CRRobotArmManager_getItsCRDisplay(const CRRobotArmManager* const me) {
    return (struct CRDisplay*)me->itsCRDisplay;
}

void CRRobotArmManager_setItsCRDisplay(CRRobotArmManager* const me, struct CRDisplay* p_CRDisplay) {
    me->itsCRDisplay = p_CRDisplay;
}

struct RobotArm* CRRobotArmManager_getItsRobotArm(const CRRobotArmManager* const me) {
    return (struct RobotArm*)me->itsRobotArm;
}

void CRRobotArmManager_setItsRobotArm(CRRobotArmManager* const me, struct RobotArm* p_RobotArm) {
    me->itsRobotArm = p_RobotArm;
}

struct UserInput* CRRobotArmManager_getItsUserInput(const CRRobotArmManager* const me) {
    return (struct UserInput*)me->itsUserInput;
}

void CRRobotArmManager_setItsUserInput(CRRobotArmManager* const me, struct UserInput* p_UserInput) {
    me->itsUserInput = p_UserInput;
}

CRRobotArmManager * CRRobotArmManager_Create(void) {
    CRRobotArmManager* me = (CRRobotArmManager *) malloc(sizeof(CRRobotArmManager));
    if(me!=NULL)
        {
            CRRobotArmManager_Init(me);
        }
    return me;
}

void CRRobotArmManager_Destroy(CRRobotArmManager* const me) {
    if(me!=NULL)
        {
            CRRobotArmManager_Cleanup(me);
        }
    free(me);
}

static void cleanUpRelations(CRRobotArmManager* const me) {
    if(me->itsCRDisplay != NULL)
        {
            me->itsCRDisplay = NULL;
        }
    if(me->itsRobotArm != NULL)
        {
            me->itsRobotArm = NULL;
        }
    if(me->itsUserInput != NULL)
        {
            me->itsUserInput = NULL;
        }
}
