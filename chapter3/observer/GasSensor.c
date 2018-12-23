#include "GasSensor.h"
#include "GasData.h"
#include "GasNotificationHandle.h"

static void cleanUpRelations(GasSensor* const me);

void GasSensor_Init(GasSensor* const me) {
    me->itsGasData = NULL;
    int pos;
    for(pos = 0; pos < 100; ++pos) {
        me->itsGasNH[pos] = NULL;
    }
}

void GasSensor_Cleanup(GasSensor* const me) {
    cleanUpRelations(me);
}

void GasSensor_dumpList(GasSensor* const me) {
    int pos;
    char s[100];
    printf("Dumping registered elements/n");
    for (pos=0; pos<100; pos++)
        if (me->itsGasNH[pos])
            if (me->itsGasNH[pos]->acceptorPtr) {
                printf("Client %d: InstancePtr=%p, acceptPtr=%p/n",
                    pos, me->itsGasNH[pos]->instancePtr, me->itsGasNH[pos]->acceptorPtr);
        };
}

void GasSensor_newData(GasSensor* const me, unsigned int flow, unsigned int n2, unsigned int o2) {
    if (!me->itsGasData)
        me->itsGasData = GasData_Create();
    me->itsGasData->flowRate = flow;
    me->itsGasData->N2Conc = n2;
    me->itsGasData->O2Conc = o2;
    GasSensor_notify(me);
}

void GasSensor_notify(GasSensor* const me) {
    int pos;
    char s[100];
    for (pos=0; pos<100; pos++)
        if (me->itsGasNH[pos])
            if (me->itsGasNH[pos]->acceptorPtr)
                me->itsGasNH[pos]->acceptorPtr(me->itsGasNH[pos]->instancePtr,me->itsGasData);
}

void GasSensor_subscribe(GasSensor* const me, void * instancePtr, const gasDataAcceptorPtr* aPtr) {
    struct GasNotificationHandle* gnh;

    gnh = GasNotificationHandle_Create();
    gnh->instancePtr = instancePtr;
    gnh->acceptorPtr = aPtr;
    GasSensor_addItsGasNH(me, gnh);
}

void GasSensor_unsubscribe(GasSensor* const me, const gasDataAcceptorPtr* aPtr) {
    int pos;
    for(pos = 0; pos < 100; ++pos) {
        if (me->itsGasNH[pos])
            if (me->itsGasNH[pos]->acceptorPtr == aPtr) {
                GasNotificationHandle_Destroy(me->itsGasNH[pos]);
                me->itsGasNH[pos] = NULL;
            }
    }
}

struct GasData* GasSensor_getItsGasData(const GasSensor* const me) {
    return (struct GasData*)me->itsGasData;
}

void GasSensor_setItsGasData(GasSensor* const me, struct GasData* p_GasData) {
    me->itsGasData = p_GasData;
}

int GasSensor_getItsGasNH(const GasSensor* const me) {
    int iter = 0;
    return iter;
}

void GasSensor_addItsGasNH(GasSensor* const me, struct GasNotificationHandle * p_GasNotificationHandle) {
    int pos;
    for(pos = 0; pos < 100; ++pos) {
        if (!me->itsGasNH[pos]) {
            me->itsGasNH[pos] = p_GasNotificationHandle;
            break;
        }
    }
}

void GasSensor_removeItsGasNH(GasSensor* const me, struct GasNotificationHandle * p_GasNotificationHandle) {
    int pos;
    for(pos = 0; pos < 100; ++pos) {
        if (me->itsGasNH[pos] == p_GasNotificationHandle) {
            me->itsGasNH[pos] = NULL;
        }
    }
}

void GasSensor_clearItsGasNH(GasSensor* const me) {
    int pos;
    for(pos = 0; pos < 100; ++pos)
    {
        me->itsGasNH[pos] = NULL;
    }
}

GasSensor * GasSensor_Create(void) {
    GasSensor* me = (GasSensor *) malloc(sizeof(GasSensor));
    if(me!=NULL) {
            GasSensor_Init(me);
    }
    return me;
}

void GasSensor_Destroy(GasSensor* const me) {
    if(me!=NULL) {
            GasSensor_Cleanup(me);
    }
    free(me);
}

static void cleanUpRelations(GasSensor* const me) {
    if(me->itsGasData != NULL) {
            me->itsGasData = NULL;
        }

}
