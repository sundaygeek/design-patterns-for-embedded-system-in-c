#ifndef WaveformDisplay_H
#define WaveformDisplay_H

#include "ECGPkg.h"

struct TMDQueue;

typedef struct WaveformDisplay WaveformDisplay;
struct WaveformDisplay
{
    int index;
    struct TMDQueue* itsTMDQueue;
};

void WaveformDisplay_Init(WaveformDisplay* const me);
void WaveformDisplay_Cleanup(WaveformDisplay* const me);

void WaveformDisplay_getScalarValue(WaveformDisplay* const me);
void WaveformDisplay_setItsTMDQueue(WaveformDisplay* const me, struct TMDQueue* p_TMDQueue);

WaveformDisplay* WaveformDisplay_Create(void);
WaveformDisplay* WaveformDisplay_Destroy(WaveformDisplay* const me);

#endif //WaveformDisplay_H
