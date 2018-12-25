#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(int argc, char const *argv[])
{
    int j,k,h,t;

    // test normal queue
    Queue* myQ;
    myQ = Queue_Create();
    k = 1000;

    for (j = 0; j < QUEUE_SIZE; ++j)
    {
        h = myQ->head;
        myQ->insert(myQ, k);
        printf("inserting %d at position %d, size=%d\n", k--, h, myQ->getSize(myQ));
    }
    printf("inserted %d element\n", myQ->getSize(myQ));

    for (j = 0; j < QUEUE_SIZE; ++j)
    {
        t = myQ->tail;
        k = myQ->remove(myQ);
        printf("removing %d at position %d, size=%d\n", k, t, myQ->getSize(myQ));
    }
    printf("last item removed %d\n", k);
    printf("current Queue size %d\n", myQ->getSize(myQ));

    return 0;
}

