#include "Sensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(int argc, char const *argv[])
{
    Sensor *p_Sensor0, *p_Sensor1;
    p_Sensor0 = Sensor_Create();
    p_Sensor1 = Sensor_Create();

    // do stuff with the sensors ere
    p_Sensor0->value = 99;
    p_Sensor1->value = 1;

    printf("The current value from Sensor0 is %d\n", Sensor_getValue(p_Sensor0));
    printf("The current value from Sensor1 is %d\n", Sensor_getValue(p_Sensor1));
    // done with sensors

    Sensor_Destroy(p_Sensor0);
    Sensor_Destroy(p_Sensor1);

    return 0;
}
