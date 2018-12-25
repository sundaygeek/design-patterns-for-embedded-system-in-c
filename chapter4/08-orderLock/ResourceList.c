#include "ResourceList.h"
#include "Mutex.h"

static char isInOrder(ResourceList* const me, int rID);

static void cleanUpRelations(ResourceList* const me);

void ResourceList_Init(ResourceList* const me) {
    me->nIDs = 0;
    me->itsMutex = NULL;
}

void ResourceList_Cleanup(ResourceList* const me) {
    cleanUpRelations(me);
}

int ResourceList_addLock(ResourceList* const me, int rID) {
    int retVal;
    Mutex_lock(me->itsMutex);
    if (isInOrder(me,rID)) {
        me->rIDList[me->nIDs++] = rID;
        retVal = 0;
        }
    else
        if (rID == me->rIDList[me->nIDs])
            retVal = DUPLICATED_IDS;
        else
            retVal = POORLY_ORDERED_ACCESS;
    Mutex_release(me->itsMutex);
    return retVal;
}

void ResourceList_removeLock(ResourceList* const me, int rID) {
    int j,k;

    if (me->nIDs) {
        for (j=0; j<me->nIDs; j++) {
            if (rID == me->rIDList[j]) {
                for (k=j; k<me->nIDs-1; k++)
                     me->rIDList[k] = me->rIDList[k+1];
                --me->nIDs;
                break;
                };
            };
    };
}

static char isInOrder(ResourceList* const me, int rID) {
    if (me->nIDs)
        return rID > me->rIDList[me->nIDs-1];
    else
        return 1;
}

struct Mutex* ResourceList_getItsMutex(const ResourceList* const me) {
    return (struct Mutex*)me->itsMutex;
}

void ResourceList_setItsMutex(ResourceList* const me, struct Mutex* p_Mutex) {
    me->itsMutex = p_Mutex;
}

ResourceList * ResourceList_Create(void) {
    ResourceList* me = (ResourceList *) malloc(sizeof(ResourceList));
    if(me!=NULL)
            ResourceList_Init(me);
    return me;
}

void ResourceList_Destroy(ResourceList* const me) {
    if(me!=NULL)
            ResourceList_Cleanup(me);
    free(me);
}

static void cleanUpRelations(ResourceList* const me) {
    if(me->itsMutex != NULL)
            me->itsMutex = NULL;
}
