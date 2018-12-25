#ifndef ResourceList_H
#define ResourceList_H

#include "OrderedLockingExample.h"
struct Mutex;

typedef struct ResourceList ResourceList;
struct ResourceList {
    int nIDs;
    int rIDList[20];
    struct Mutex* itsMutex;
};

/* Constructors and destructors:*/
void ResourceList_Init(ResourceList* const me);
void ResourceList_Cleanup(ResourceList* const me);

/* Operations */
int ResourceList_addLock(ResourceList* const me, int rID);

/*    The elements are added in order but */
/*    can be removed in any order. Therefore, */
/*    the stored resoiurceIDs above the current */
/*    one in the list must be moved down to  */
/*    lower in the list. */
void ResourceList_removeLock(ResourceList* const me, int rID);

struct Mutex* ResourceList_getItsMutex(const ResourceList* const me);

void ResourceList_setItsMutex(ResourceList* const me, struct Mutex* p_Mutex);

ResourceList * ResourceList_Create(void);

void ResourceList_Destroy(ResourceList* const me);

#endif
