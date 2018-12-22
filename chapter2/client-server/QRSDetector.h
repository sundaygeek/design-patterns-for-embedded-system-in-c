#ifndef QRSDetector_H
#define QRSDetector_H

#include "ECGPkg.h"

// https://en.wikipedia.org/wiki/QRS_complex

struct TMDQueue;

typedef struct QRSDetector QRSDetector;
struct QRSDetector
{
    int heartRate;
    int index;
    struct TMDQueue* itsTMDQueue;
};

// constructions and desctructions
void QRSDetector_Init(QRSDetector* const me);
void QRSDetector_Cleanup(QRSDetector* const me);

void QRSDetector_computeHR(QRSDetector* const me);
void QRSDetector_getDataSample(QRSDetector* const me);
void QRSDetector_setItsTMDQueue(QRSDetector* const me, struct TMDQueue* p_TMDQueue);
struct TMDQueue* QRSDetector_getItsTMDQueue(const QRSDetector* const me);

QRSDetector * QRSDetector_Create(void);
QRSDetector * QRSDetector_Destroy(QRSDetector* const me);


#endif // QRSDetector_H
