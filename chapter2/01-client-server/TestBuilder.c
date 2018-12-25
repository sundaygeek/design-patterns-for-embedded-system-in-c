#include "TestBuilder.h"
#include <stdlib.h>

static void initRelations(TestBuilder* const me);
static void cleanUpRelations(TestBuilder* const me);

void TestBuilder_Init(TestBuilder* const me) {
    initRelations(me);
}

void TestBuilder_Cleanup(TestBuilder* const me) {
    cleanUpRelations(me);
}

struct ArrhythmiaDetector* TestBuilder_getItsArrhythmiaDetector(const TestBuilder* const me) {
    return (struct ArrhythmiaDetector*)&(me->itsArrhythmiaDetector);
}

struct ECG_Module* TestBuilder_getItsECG_Module(const TestBuilder* const me) {
    return (struct ECG_Module*)&(me->itsECG_Module);
}

struct HistogramDisplay* TestBuilder_getItsHistogramDisplay(const TestBuilder* const me) {
    return (struct HistogramDisplay*)&(me->itsHistogramDisplay);
}

struct QRSDetector* TestBuilder_getItsQRSDetector(const TestBuilder* const me) {
    return (struct QRSDetector*)&(me->itsQRSDetector);
}

struct TMDQueue* TestBuilder_getItsTMDQueue(const TestBuilder* const me) {
    return (struct TMDQueue*)&(me->itsTMDQueue);
}

struct WaveformDisplay* TestBuilder_getItsWaveformDisplay(const TestBuilder* const me) {
    return (struct WaveformDisplay*)&(me->itsWaveformDisplay);
}

TestBuilder * TestBuilder_Create(void) {
    TestBuilder* me = (TestBuilder *) malloc(sizeof(TestBuilder));
    if(me!=NULL)
    {
        TestBuilder_Init(me);
    }
    return me;
}

void TestBuilder_Destroy(TestBuilder* const me) {
    if(me!=NULL)
    {
        TestBuilder_Cleanup(me);
    }
    free(me);
}

static void initRelations(TestBuilder* const me) {
    ArrhythmiaDetector_Init(&(me->itsArrhythmiaDetector));
    ECG_Module_Init(&(me->itsECG_Module));
    HistogramDisplay_Init(&(me->itsHistogramDisplay));
    QRSDetector_Init(&(me->itsQRSDetector));
    TMDQueue_Init(&(me->itsTMDQueue));
    WaveformDisplay_Init(&(me->itsWaveformDisplay));

    ECG_Module_setItsTMDQueue(&(me->itsECG_Module), &(me->itsTMDQueue));
    HistogramDisplay_setItsTMDQueue(&(me->itsHistogramDisplay), &(me->itsTMDQueue));
    QRSDetector_setItsTMDQueue(&(me->itsQRSDetector), &(me->itsTMDQueue));
    WaveformDisplay_setItsTMDQueue(&(me->itsWaveformDisplay), &(me->itsTMDQueue));
    ArrhythmiaDetector_setItsTMDQueue(&(me->itsArrhythmiaDetector), &(me->itsTMDQueue));
}

static void cleanUpRelations(TestBuilder* const me) {
    WaveformDisplay_Cleanup(&(me->itsWaveformDisplay));
    TMDQueue_Cleanup(&(me->itsTMDQueue));
    QRSDetector_Cleanup(&(me->itsQRSDetector));
    HistogramDisplay_Cleanup(&(me->itsHistogramDisplay));
    ECG_Module_Cleanup(&(me->itsECG_Module));
    ArrhythmiaDetector_Cleanup(&(me->itsArrhythmiaDetector));
}
