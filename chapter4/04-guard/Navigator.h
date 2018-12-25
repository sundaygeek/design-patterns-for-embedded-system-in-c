#ifndef Navigator_H
#define Navigator_H

#include "GuardedCallExample.h"
#include "Position.h"
struct KinematicData;

typedef struct Navigator Navigator;
struct Navigator {
    struct Position ownShipPosition;
    struct KinematicData* itsKinematicData;
};

/* Constructors and destructors:*/

void Navigator_Init(Navigator* const me);
void Navigator_Cleanup(Navigator* const me);

/* Operations */
void Navigator_updatePosition(Navigator* const me);

struct KinematicData* Navigator_getItsKinematicData(const Navigator* const me);

void Navigator_setItsKinematicData(Navigator* const me, struct KinematicData* p_KinematicData);

Navigator * Navigator_Create(void);

void Navigator_Destroy(Navigator* const me);

#endif
