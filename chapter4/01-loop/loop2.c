#include <stdio.h>

/*
    here is where private static data goes
*/
static int taskAInvocationCounter=0;

void taskA(void) {
    /* more private task data */
    int stufftoDo;

    /* initialization code */
    stuffToDo = 1;
    while (stuffToDo) {
        signal = waitOnSignal();
        switch (signal) {
            case signal1:
                /* signal 1 processing here */
                break;
            case signal2:
                /* signal 2 processing here */
            case signal3:
                /* signal 3 processing here */
        };
    }; /* end infinite while loop */
}; /* end task */

int main(int argc, char const *argv[])
{
    taskA();
    return 0;
}
