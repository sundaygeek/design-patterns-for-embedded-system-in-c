#ifndef AlertManager_H
#define AlertManager_H

typedef struct AlarmManager AlarmManager;
struct AlarmManager
{

};

void AlarmManager_Init(AlarmManager* const me);
void AlarmManager_Cleanup(AlarmManager* const me);
AlarmManager* AlarmManager_Create(void);
void AlarmManager_Destroy(AlarmManager* const me);

#endif
