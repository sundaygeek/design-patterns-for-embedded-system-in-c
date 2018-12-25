#ifndef GuardedCallExample_H
#define GuardedCallExample_H


struct Attitude;
struct AttitudeController;
struct FlightDataDisplay;
struct GuardTester;
struct GuardedCallBuilder;
struct KinematicData;
struct Navigator;
struct Position;

/* OS provided types and functions */
struct OSSemaphore;
struct OSSemaphore* OS_create_semaphore(void);
void OS_destroy_semaphore(struct OSSemaphore* sPtr);
void OS_lock_semaphore(struct OSSemaphore* sPtr);
void OS_release_semaphore(struct OSSemaphore* sPtr);

#endif
