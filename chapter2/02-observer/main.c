#include "ECGPkg.h"
#include "TestBuilder.h"

int main(int argc, char* argv[]) {
    int status = 0;

    TestBuilder * p_TestBuilder;
    p_TestBuilder = TestBuilder_Create();
    ECG_Module_acquireValue(&(p_TestBuilder->itsECG_Module));
    ECG_Module_acquireValue(&(p_TestBuilder->itsECG_Module));
    ECG_Module_acquireValue(&(p_TestBuilder->itsECG_Module));
    ECG_Module_acquireValue(&(p_TestBuilder->itsECG_Module));
    ECG_Module_acquireValue(&(p_TestBuilder->itsECG_Module));

    HistogramDisplay_getValue(&(p_TestBuilder->itsHistogramDisplay));
    HistogramDisplay_getValue(&(p_TestBuilder->itsHistogramDisplay));
    HistogramDisplay_getValue(&(p_TestBuilder->itsHistogramDisplay));
    HistogramDisplay_getValue(&(p_TestBuilder->itsHistogramDisplay));
    HistogramDisplay_getValue(&(p_TestBuilder->itsHistogramDisplay));

    // QRSDetector_getDataSample(&(p_TestBuilder->itsQRSDetector));
    // QRSDetector_getDataSample(&(p_TestBuilder->itsQRSDetector));
    // QRSDetector_getDataSample(&(p_TestBuilder->itsQRSDetector));

    // WaveformDisplay_getScalarValue(&(p_TestBuilder->itsWaveformDisplay));
    // WaveformDisplay_getScalarValue(&(p_TestBuilder->itsWaveformDisplay));
    // WaveformDisplay_getScalarValue(&(p_TestBuilder->itsWaveformDisplay));
    // WaveformDisplay_getScalarValue(&(p_TestBuilder->itsWaveformDisplay));
    // WaveformDisplay_getScalarValue(&(p_TestBuilder->itsWaveformDisplay));

    // ArrhythmiaDetector_getDataSample(&(p_TestBuilder->itsArrhythmiaDetector));
    // ArrhythmiaDetector_getDataSample(&(p_TestBuilder->itsArrhythmiaDetector));
    // ArrhythmiaDetector_getDataSample(&(p_TestBuilder->itsArrhythmiaDetector));
    // ArrhythmiaDetector_getDataSample(&(p_TestBuilder->itsArrhythmiaDetector));
    // ArrhythmiaDetector_getDataSample(&(p_TestBuilder->itsArrhythmiaDetector));

    printf("Done\n");
    TestBuilder_Destroy(p_TestBuilder);
    return 0;
}
