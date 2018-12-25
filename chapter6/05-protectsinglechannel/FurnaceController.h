#ifndef FurnaceController_H
#define FurnaceController_H

typedef struct FurnaceController FurnaceController;
struct FurnaceController
{

};

void FurnaceController_emergencyRestart(FurnaceController* const me);
void FurnaceController_shutDown(FurnaceController* const me);

#endif
