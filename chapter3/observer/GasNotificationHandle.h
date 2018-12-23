#ifndef GasNotificationHandle_H
#define GasNotificationHandleH

typedef struct GasNotificationHandle GasNotificationHandle;
struct GasNotificationHandle
{
    void (*acceptorPtr)(void *, struct GasData*);
    void* instancePtr;
};

void GasNotificationHandle_Init(GasNotificationHandle* const me);
void GasNotificationHandle_Cleanup(GasNotificationHandle* const me);

GasNotificationHandle * GasNotificationHandle_Create(void);
void GasNotificationHandle_Destroy(GasNotificationHandle* const me);

#endif
