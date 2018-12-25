#ifndef MotorController_H
#define MotorController_H

void MotorController_Init(void);
void MotorController_Cleanup(void);

void MotorController_run(void);
void move(void);
void zero(void);

void MotorController_initRelations(void);

#endif
