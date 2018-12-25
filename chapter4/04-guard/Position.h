#ifndef Position_H
#define Position_H

#include "GuardedCallExample.h"

typedef struct Position Position;
struct Position {
    double altitude;        /*## attribute altitude */
    double latitude;        /*## attribute latitude */
    double longitude;       /*## attribute longitude */
};

/* Constructors and destructors:*/
void Position_Init(Position* const me);
void Position_Cleanup(Position* const me);

/* Operations */
double Position_getAltitude(Position* const me);
double Position_getLatitude(Position* const me);
double Position_getLongitude(Position* const me);
void Position_setAltitude(Position* const me, double x);
void Position_setLatitude(Position* const me, double x);
void Position_setLongitude(Position* const me, double x);

Position * Position_Create(void);
void Position_Destroy(Position* const me);

#endif
