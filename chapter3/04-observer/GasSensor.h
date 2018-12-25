#ifndef GasSensor_H
#define GasSensor_H

#include "GasData.h"
#include "GasNotificationHandle.h"
#include <stdio.h>
#include <stdlib.h>

/* the function pointer type
  The first value of the function pointer is to the instance
  data of the class. The second is a ptr to the new gas data
*/
typedef void (*gasDataAcceptorPtr)(void *, struct GasData*);

struct GasNotificationHandle;

/* class GasSensor */
typedef struct GasSensor GasSensor;
struct GasSensor {
    struct GasData* itsGasData;
    struct GasNotificationHandle *itsGasNH[100];
};

/* Constructors and destructors:*/
void GasSensor_Init(GasSensor* const me);
void GasSensor_Cleanup(GasSensor* const me);


/* Operations */
void GasSensor_dumpList(GasSensor* const me);
void GasSensor_newData(GasSensor* const me, unsigned int flow, unsigned int n2, unsigned int o2);
void GasSensor_notify(GasSensor* const me);
void GasSensor_subscribe(GasSensor* const me, void * instancePtr, const gasDataAcceptorPtr* aPtr);
void GasSensor_unsubscribe(GasSensor* const me, const gasDataAcceptorPtr* aPtr);
struct GasData* GasSensor_getItsGasData(const GasSensor* const me);
void GasSensor_setItsGasData(GasSensor* const me, struct GasData* p_GasData);
int GasSensor_getItsGasNH(const GasSensor* const me);
void GasSensor_addItsGasNH(GasSensor* const me, struct GasNotificationHandle * p_GasNotificationHandle);
void GasSensor_removeItsGasNH(GasSensor* const me, struct GasNotificationHandle * p_GasNotificationHandle);
void GasSensor_clearItsGasNH(GasSensor* const me);
GasSensor * GasSensor_Create(void);
void GasSensor_Destroy(GasSensor* const me);

#endif
