#include "Navigator.h"
#include "KinematicData.h"

static void cleanUpRelations(Navigator* const me);

void Navigator_Init(Navigator* const me) {
    Position_Init(&(me->ownShipPosition));
    me->itsKinematicData = NULL;
}

void Navigator_Cleanup(Navigator* const me) {
    cleanUpRelations(me);
}

void Navigator_updatePosition(Navigator* const me) {
    KinematicData_setPosition(me->itsKinematicData, me->ownShipPosition);
}

struct KinematicData* Navigator_getItsKinematicData(const Navigator* const me) {
    return (struct KinematicData*)me->itsKinematicData;
}

void Navigator_setItsKinematicData(Navigator* const me, struct KinematicData* p_KinematicData) {
    me->itsKinematicData = p_KinematicData;
}

Navigator * Navigator_Create(void) {
    Navigator* me = (Navigator *) malloc(sizeof(Navigator));
    if(me!=NULL) {
        Navigator_Init(me);
    }
    return me;
}

void Navigator_Destroy(Navigator* const me) {
    if(me!=NULL) {
        Navigator_Cleanup(me);
     }
    free(me);
}

static void cleanUpRelations(Navigator* const me) {
    if(me->itsKinematicData != NULL) {
        me->itsKinematicData = NULL;
    }
}
