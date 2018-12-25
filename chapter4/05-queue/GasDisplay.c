#include "GasDisplay.h"
#include <stdio.h>

void GasDisplay_Init(GasDisplay* const me) {
    me->screenWidth = 80;
}

void GasDisplay_Cleanup(GasDisplay* const me) {
}

void GasDisplay_printGasData(GasDisplay* const me, const GAS_TYPE gasType, double gas_conc, unsigned int gas_flow) {
    printf("\n");
    switch (gasType) {
        case O2_GAS:
            printf("Oxygen   ");
            break;
        case N2_GAS:
            printf("Nitrogen ");
            break;
        case HE_GAS:
            printf("Helium   ");
            break;
        default:
                printf("UNKNWON  ");
                break;
    };
    printf("Conc %f, Flow in CC/Min %d\n", gas_conc, gas_flow);
    printf("\n");
}

GasDisplay * GasDisplay_Create(void) {
    GasDisplay* me = (GasDisplay *) malloc(sizeof(GasDisplay));
    if(me!=NULL) {
        GasDisplay_Init(me);
    }
    return me;
}

void GasDisplay_Destroy(GasDisplay* const me) {
    if(me!=NULL) {
        GasDisplay_Cleanup(me);
    }
    free(me);
}
