#ifndef QueuingExample_H
#define QueuingExample_H

#include <stdio.h>
#include <stdlib.h>

struct GasController;
struct GasData;
struct GasDataQueue;
struct GasDisplay;
struct GasProcessingThread;
struct HeSensor;
struct N2Sensor;
struct O2Sensor;
struct OSSemaphore;
struct SensorThread;

typedef enum GAS_TYPE {
    O2_GAS,
    N2_GAS,
    HE_GAS,
    UNKNOWN_GAS
} GAS_TYPE;

/* define the size of the queue */
#define GAS_QUEUE_SIZE (10)

/* OS semaphore services */
struct OSSemaphore* OS_create_semaphore(void);
void OS_destroy_semaphore(struct OSSemaphore* sPtr);
void OS_lock_semaphore(struct OSSemaphore* sPtr);
void OS_release_semaphore(struct OSSemaphore* sPtr);

#endif
