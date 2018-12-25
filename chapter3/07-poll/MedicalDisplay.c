#include "MedicalDisplay.h"

void MedicalDisplay_Init(MedicalDisplay* const me){

}
void MedicalDisplay_Cleanup(MedicalDisplay* const me){

}

MedicalDisplay* MedicalDisplay_Create(){
    MedicalDisplay* me = (MedicalDisplay*)malloc(sizeof(MedicalDisplay));
    if (me != NULL)
    {
        MedicalDisplay_Init(me);
    }
    return me;
}

void MedicalDisplay_Destroy(MedicalDisplay* me){
    if (me != NULL)
    {
        MedicalDisplay_Cleanup(me);
    }
    free(me);
}

void MedicalDisplay_showO2Concentration(MedicalDisplay* const me, int data){
    printf("call MedicalDisplay_showO2Concentration, data:%d\n", data);
}
void MedicalDisplay_showGasFlow(MedicalDisplay* const me, int data){
    printf("call MedicalDisplay_showGasFlow, data:%d\n", data);
}
void MedicalDisplay_showGasFlowStatus(MedicalDisplay* const me, int state){
    printf("call MedicalDisplay_showGasFlowStatus, state:%d\n", state);
}
void MedicalDisplay_showCircuitPressure(MedicalDisplay* const me, int data){
    printf("call MedicalDisplay_showCircuitPressure, data:%d\n", data);
}
