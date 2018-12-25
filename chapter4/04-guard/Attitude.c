#include "Attitude.h"

void Attitude_Init(Attitude* const me) {
}

void Attitude_Cleanup(Attitude* const me) {
}

double Attitude_getPitch(Attitude* const me) {
    return me->pitch;
}

double Attitude_getRoll(Attitude* const me) {
    return me->roll;
}

double Attitude_getYaw(Attitude* const me) {
    return me->yaw;
}

void Attitude_setPitch(Attitude* const me, double x) {
    me->pitch = x;
}

void Attitude_setRoll(Attitude* const me, double x) {
    me->roll = x;
}

void Attitude_setYaw(Attitude* const me, double x) {
    me->yaw = x;
}

Attitude * Attitude_Create(void) {
    Attitude* me = (Attitude *) malloc(sizeof(Attitude));
    if(me!=NULL)
        {
            Attitude_Init(me);
        }
    return me;
}

void Attitude_Destroy(Attitude* const me) {
    if(me!=NULL)
        {
            Attitude_Cleanup(me);
        }
    free(me);
}
