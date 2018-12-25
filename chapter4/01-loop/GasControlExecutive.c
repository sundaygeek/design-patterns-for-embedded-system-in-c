#include "GasControlExecutive.h"
#include "GasActuatorThread.h"
#include "GasControlEpochTimer.h"
#include "GasDisplayThread.h"
#include "GasSensorThread.h"

void controlLoop(void) {
    while (TRUE) {
        startEpochTimer();
        GasSensorThread_run();
        GasActuatorThread_run();
        GasDisplayThread_run();
        while(!epochTimerHasElapsed()) ;
    };
}
