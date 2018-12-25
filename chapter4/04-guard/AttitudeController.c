#include "AttitudeController.h"
#include "KinematicData.h"

static void cleanUpRelations(AttitudeController* const me);

void AttitudeController_Init(AttitudeController* const me) {
    Attitude_Init(&(me->ownShipAttitude));
    me->itsKinematicData = NULL;
}

void AttitudeController_Cleanup(AttitudeController* const me) {
    cleanUpRelations(me);
}

void AttitudeController_manageAttitude(AttitudeController* const me) {
    KinematicData_setAttitude(me->itsKinematicData, me->ownShipAttitude);
}

struct KinematicData* AttitudeController_getItsKinematicData(const AttitudeController* const me) {
    return (struct KinematicData*)me->itsKinematicData;
}

void AttitudeController_setItsKinematicData(AttitudeController* const me, struct KinematicData* p_KinematicData) {
    me->itsKinematicData = p_KinematicData;
}

AttitudeController * AttitudeController_Create(void) {
    AttitudeController* me = (AttitudeController *) malloc(sizeof(AttitudeController));
    if(me!=NULL) {
        AttitudeController_Init(me);
    }
    return me;
}

void AttitudeController_Destroy(AttitudeController* const me) {
    if(me!=NULL) {
        AttitudeController_Cleanup(me);
    }
    free(me);
}

static void cleanUpRelations(AttitudeController* const me) {
    if(me->itsKinematicData != NULL) {
        me->itsKinematicData = NULL;
    }
}
