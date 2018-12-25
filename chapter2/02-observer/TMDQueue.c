#include "TMDQueue.h"
#include "NotificationHandle.h"

static void initRelations(TMDQueue* const me);
static void cleanUpRelations(TMDQueue* const me);

void TMDQueue_Init(TMDQueue* const me) {
    me->head = 0;
    me->nSubscribers = 0;
    me->size = 0;
    me->itsNotificationHandle = NULL;
    initRelations(me);
}

void TMDQueue_Cleanup(TMDQueue* const me) {
    cleanUpRelations(me);
}

int TMDQueue_getNextIndex(TMDQueue* const me, int index) {
     /* this operation computes the next index from the
     first using modulo arithmetic
     */
    return (index+1) % QUEUE_SIZE;
}

void TMDQueue_insert(TMDQueue* const me, const struct TimeMarkedData tmd) {
    /* note that because we never 'remove' data from this
    leaky queue, size only increases to the queue size and
    then stops increasing. Inserion always takes place at the head.
    */
    printf("Inderting at: %d    Data #: %d", me->head, tmd.timeInterval);
    me->buffer[me->head] = tmd;
    me->head = TMDQueue_getNextIndex(me, me->head);
    if (me->size < QUEUE_SIZE) ++me->size;
    printf("  Storing data value: %d\n", tmd.dataValue);
    TMDQueue_notify(me, tmd);
}

boolean TMDQueue_isEmpty(TMDQueue* const me) {
    return (boolean)(me->size == 0);
}

void TMDQueue_notify(TMDQueue* const me, const struct TimeMarkedData tmd) {
    NotificationHandle *pNH;
    pNH= me->itsNotificationHandle;
    while (pNH) {
        printf("----->> calling updateAddr on pNH %d\n",pNH);
        pNH->updateAddr(NULL, tmd);
        pNH = pNH->itsNotificationHandle;
    };
}

struct TimeMarkedData TMDQueue_remove(TMDQueue* const me, int index) {
     TimeMarkedData tmd;
     tmd.timeInterval=-1; /* sentinel values */
     tmd.dataValue=-9999;

    if (!TMDQueue_isEmpty(me) &&
        (index>=0) &&
        (index < QUEUE_SIZE)
        && (index < me->size)) {
        tmd = me->buffer[index];
    }
    return tmd;
}

void TMDQueue_subscribe(TMDQueue* const me, const UpdateFuncPtr updateFuncAddr) {
    struct NotificationHandle *pNH;
    pNH = me->itsNotificationHandle;

    if (!pNH) { /* empty list? */
        /* create a new Notification Handle, initialize it, and point to it */
        printf("------> Added to a new list\n");
        me->itsNotificationHandle = NotificationHandle_Create();
        printf("------> Called NH_Create()\n");
        pNH = me->itsNotificationHandle;
    }
    else
    {
        /* search list to find end */
        printf("------> Adding to an existing list\n");
        while (pNH->itsNotificationHandle != NULL) {
            printf("Getting ready to augment ptr %d to %d\n", pNH, pNH->itsNotificationHandle);
            pNH = pNH->itsNotificationHandle;  /* get next element in list */
            printf("------> augmenting ptr\n");
        };
        printf("------> calling NH_Create\n");
        pNH->itsNotificationHandle = NotificationHandle_Create();
        pNH = pNH->itsNotificationHandle; /* pt to the new instance */
        printf("------> called NH_Create()\n");
    }; /* end if */

    /* pNH now points to an constructed Notification Handle */
    pNH->updateAddr = updateFuncAddr;  /* set callback address */
    ++me->nSubscribers;
    printf("------> wrote updateAddr \n");
    if (pNH->itsNotificationHandle)
        printf("xxxxxxx> next Ptr not null!\n\n");
    else
        printf("------> next ptr null\n\n");
}

int TMDQueue_unsubscribe(TMDQueue* const me, const UpdateFuncPtr updateFuncAddr) {
    struct NotificationHandle *pNH, *pBack;
    pNH = pBack = me->itsNotificationHandle;

    if (pNH == NULL) { /* empty list? */
        return 0; /* can't delete it from an empty list */
    }
    else
    { /* it it the first one? */
        if (pNH->updateAddr == updateFuncAddr) {
            me->itsNotificationHandle = pNH->itsNotificationHandle;
            free(pNH);
            printf(">>>>>> Removing the first element\n");
            --me->nSubscribers;
            return 1;
        }
        else
        { /* search list to find element */
            printf(">>>>>> Searching....\n");
            while (pNH != NULL) {
                if (pNH->updateAddr != updateFuncAddr) {
                    pBack->itsNotificationHandle = pNH->itsNotificationHandle;
                    free(pNH);
                    printf(">>>>>> Removing subscriber in list\n");
                    --me->nSubscribers;
                    return 1;
                    }; /* end if found */
                pBack = pNH; /* points to the list element before pNH */
                pNH = pNH->itsNotificationHandle;  /* get next element in list */
            }; /* end while */
        };  /* end else */

        printf(">>>>>> Didn't remove any subscribers\n");
        return 0;
    }; /* non-empty list */
}

int TMDQueue_getBuffer(const TMDQueue* const me) {
    int iter = 0;
    return iter;
}

struct NotificationHandle* TMDQueue_getItsNotificationHandle(const TMDQueue* const me) {
    return (struct NotificationHandle*)me->itsNotificationHandle;
}

void TMDQueue_setItsNotificationHandle(TMDQueue* const me, struct NotificationHandle* p_NotificationHandle) {
    me->itsNotificationHandle = p_NotificationHandle;
}

TMDQueue * TMDQueue_Create(void) {
    TMDQueue* me = (TMDQueue *) malloc(sizeof(TMDQueue));
    if(me!=NULL)
    {
        TMDQueue_Init(me);
    }
    return me;
}

void TMDQueue_Destroy(TMDQueue* const me) {
    if(me!=NULL)
    {
        TMDQueue_Cleanup(me);
    }
    free(me);
}

static void initRelations(TMDQueue* const me) {
    {
        int iter = 0;
        while (iter < QUEUE_SIZE){
            TimeMarkedData_Init(&((me->buffer)[iter]));
            TimeMarkedData__setItsTMDQueue(&((me->buffer)[iter]), me);
            iter++;
        }
    }
}

static void cleanUpRelations(TMDQueue* const me) {
    {
        int iter = 0;
        while (iter < QUEUE_SIZE){
            TimeMarkedData_Cleanup(&((me->buffer)[iter]));
            iter++;
        }
    }
    if(me->itsNotificationHandle != NULL)
    {
        me->itsNotificationHandle = NULL;
    }
}
