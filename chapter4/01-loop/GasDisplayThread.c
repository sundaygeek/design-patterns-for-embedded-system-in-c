#include "GasDisplayThread.h"

void GasDisplayThread_run(void) {
    printf("Measured Gas Flow %d\n", measuredGasFlow);
    printf("commanded Gas Flow %d\n\n", commandedGasFlow);
}
