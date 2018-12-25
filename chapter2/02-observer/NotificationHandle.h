#ifndef NotificationHandle_H
#define NotificationHandle_H

#include <stdio.h>
#include "ECGPkg.h"

typedef struct NotificationHandle NotificationHandle;
struct NotificationHandle {
    UpdateFuncPtr updateAddr;
    struct NotificationHandle* itsNotificationHandle;
};

/* Constructors and destructors:*/
void NotificationHandle_Init(NotificationHandle* const me);
void NotificationHandle_Cleanup(NotificationHandle* const me);

struct NotificationHandle* NotificationHandle_getItsNotificationHandle(const NotificationHandle* const me);
void NotificationHandle_setItsNotificationHandle(NotificationHandle* const me, struct NotificationHandle* p_NotificationHandle);

NotificationHandle * NotificationHandle_Create(void);
void NotificationHandle_Destroy(NotificationHandle* const me);

#endif
