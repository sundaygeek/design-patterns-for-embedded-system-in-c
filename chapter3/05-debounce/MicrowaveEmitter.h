#ifndef MicrowaveEmitter_H
#define MicrowaveEmitter_H

#include <stdio.h>
#include <stdlib.h>

typedef struct MicrowaveEmitter MicrowaveEmitter;
struct MicrowaveEmitter
{
    int deviceState;
};

void MicrowaveEmitter_Init(MicrowaveEmitter* const me);
void MicrowaveEmitter_Cleanup(MicrowaveEmitter* const me);

MicrowaveEmitter* MicrowaveEmitter_Create();
void MicrowaveEmitter_Destroy(MicrowaveEmitter* const me);

void MicrowaveEmitter_startEmitting(MicrowaveEmitter* const me);
void MicrowaveEmitter_stopEmitting(MicrowaveEmitter* const me);

#endif
