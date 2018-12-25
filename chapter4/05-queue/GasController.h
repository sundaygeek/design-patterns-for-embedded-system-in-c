#ifndef GasController_H
#define GasController_H

#include <stdio.h>
#include <stdlib.h>
#include "QueuingExample.h"
#include "GasData.h"
struct GasDisplay;

typedef struct GasController GasController;
struct GasController {
    struct GasDisplay* itsGasDisplay;
};


/* Constructors and destructors:*/

void GasController_Init(GasController* const me);
void GasController_Cleanup(GasController* const me);

/* Operations */
void GasController_handleGasData(GasController* const me, GasData * gPtr);

struct GasDisplay* GasController_getItsGasDisplay(const GasController* const me);

void GasController_setItsGasDisplay(GasController* const me, struct GasDisplay* p_GasDisplay);

GasController * GasController_Create(void);

void GasController_Destroy(GasController* const me);

#endif
