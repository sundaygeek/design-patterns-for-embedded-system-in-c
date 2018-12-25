#include "FlightDataDisplay.h"
#include "KinematicData.h"
#include <stdio.h>

static void cleanUpRelations(FlightDataDisplay* const me);

void FlightDataDisplay_Init(FlightDataDisplay* const me) {
    me->itsKinematicData = NULL;
}

void FlightDataDisplay_Cleanup(FlightDataDisplay* const me) {
    cleanUpRelations(me);
}

void FlightDataDisplay_showFlightData(FlightDataDisplay* const me) {
    Attitude a;
    Position p;
    a = KinematicData_getAttitude(me->itsKinematicData);
    p = KinematicData_getPosition(me->itsKinematicData);
    printf("Roll, pitch, yaw = %f, %f, %f \n", a.roll, a.pitch, a.yaw);
    printf("Lat, Long, Altitude = %f, %f, %f\n", p.latitude, p.longitude, p.altitude);
}

struct KinematicData* FlightDataDisplay_getItsKinematicData(const FlightDataDisplay* const me) {
    return (struct KinematicData*)me->itsKinematicData;
}

void FlightDataDisplay_setItsKinematicData(FlightDataDisplay* const me, struct KinematicData* p_KinematicData) {
    me->itsKinematicData = p_KinematicData;
}

FlightDataDisplay * FlightDataDisplay_Create(void) {
    FlightDataDisplay* me = (FlightDataDisplay *) malloc(sizeof(FlightDataDisplay));
    if(me!=NULL) {
        FlightDataDisplay_Init(me);
    }
    return me;
}

void FlightDataDisplay_Destroy(FlightDataDisplay* const me) {
    if(me!=NULL) {
        FlightDataDisplay_Cleanup(me);
    }
    free(me);
}

static void cleanUpRelations(FlightDataDisplay* const me) {
    if(me->itsKinematicData != NULL) {
        me->itsKinematicData = NULL;
    }
}
