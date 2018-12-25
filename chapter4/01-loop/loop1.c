#include <stdio.h>

void main(void) {
    /* global static and stack data */
    static int nTasks = 3;
    int currentTask;

    /* initialization code */
    currentTask = 0;

    if (POST()) { /* Power On Self Test succeeds */
        /* scheduling executive */
        while (TRUE) {
            task1();
            task2();
            task3();
        }; /* end cyclic processing loop */
    }
}
