#ifndef MotorPositionSensor_H
#define MotorPositionSensor_H

void MotorPositionSensor_Init(void);
void MotorPositionSensor_Cleanup(void);

void MotorPositionSensor_run(void);
void getPosition(void);

void MotorPositionSensor_initRelations(void);

#endif
