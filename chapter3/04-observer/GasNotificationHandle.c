#include "GasNotificationHandle.h"

void GasNotificationHandle_Init(GasNotificationHandle* const me){

}
void GasNotificationHandle_Cleanup(GasNotificationHandle* const me){

}

GasNotificationHandle * GasNotificationHandle_Create(void){
    GasNotificationHandle* me = (GasNotificationHandle*)malloc(sizeof(GasNotificationHandle));
    if (me != NULL)
    {
        GasNotificationHandle_Init(me);
    }
    return me;
}
void GasNotificationHandle_Destroy(GasNotificationHandle* const me){
    if (me != NULL)
    {
        GasNotificationHandle_Cleanup(me);
    }
    free(me);
}
