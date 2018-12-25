#include <stdio.h>
#include <stdlib.h>
#include "BCPeriodicPoller.h"

int main(int argc, char const *argv[])
{
    BCPeriodicPoller* p_BCPeriodicPoller = BCPeriodicPoller_Create();
    BCPeriodicPoller_poll(p_BCPeriodicPoller);
    return 0;
}
