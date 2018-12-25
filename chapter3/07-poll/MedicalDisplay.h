#ifndef MedicalDisplay_H
#define MedicalDisplay_H

#include <stdio.h>
#include <stdlib.h>

typedef struct MedicalDisplay MedicalDisplay;
struct MedicalDisplay
{

};

void MedicalDisplay_Init(MedicalDisplay* const me);
void MedicalDisplay_Cleanup(MedicalDisplay* const me);

MedicalDisplay* MedicalDisplay_Create();
void MedicalDisplay_Destroy(MedicalDisplay* me);

void MedicalDisplay_showO2Concentration(MedicalDisplay* const me, int data);
void MedicalDisplay_showGasFlow(MedicalDisplay* const me, int data);
void MedicalDisplay_showGasFlowStatus(MedicalDisplay* const me, int state);
void MedicalDisplay_showCircuitPressure(MedicalDisplay* const me, int data);

#endif
