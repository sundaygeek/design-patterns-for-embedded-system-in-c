#include "GasData.h"

void GasData_Init(GasData* const me) {
}

void GasData_Cleanup(GasData* const me) {
}

GasData * GasData_Create(void) {
    GasData* me = (GasData *) malloc(sizeof(GasData));
    if(me!=NULL) {
        GasData_Init(me);
    }
    return me;
}

void GasData_Destroy(GasData* const me) {
    if(me!=NULL) {
        GasData_Cleanup(me);
    }
    free(me);
}

