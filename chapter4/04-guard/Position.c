#include "Position.h"

void Position_Init(Position* const me) {
}

void Position_Cleanup(Position* const me) {
}

double Position_getAltitude(Position* const me) {
    return me->altitude;
}

double Position_getLatitude(Position* const me) {
    return me->latitude;
}

double Position_getLongitude(Position* const me) {
    return me->longitude;
}

void Position_setAltitude(Position* const me, double x) {
    me->altitude = x;
}

void Position_setLatitude(Position* const me, double x) {
    me->latitude = x;
}

void Position_setLongitude(Position* const me, double x) {
    me->longitude = x;
}

Position * Position_Create(void) {
    Position* me = (Position *) malloc(sizeof(Position));
    if(me!=NULL) {
            Position_Init(me);
    }
    return me;
}

void Position_Destroy(Position* const me) {
    if(me!=NULL) {
         Position_Cleanup(me);
    }
     free(me);
}
