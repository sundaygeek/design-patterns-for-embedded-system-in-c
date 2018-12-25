#ifndef ECGPkg_H
#define ECGPkg_H

// electrocardiogram  ECG

#include <stdio.h>
#include <stdlib.h>

/* forward declarations */
struct ArrythmiaDetector;
struct ECG_Module;
struct HistogramDisplay;
struct QRSDetector;
struct TMDQueue;
struct TestBuilder;
struct TimeMarkedData;
struct WaveformDisplay;

typedef unsigned char boolean;
#define QUEUE_SIZE (20000)

#endif //ECGPkg_H
