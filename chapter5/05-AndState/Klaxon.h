#ifndef Klaxon_H
#define Klaxon_H

typedef struct Klaxon Klaxon;
struct Klaxon
{

};

void Klaxon_Init(Klaxon* const me);
void Klaxon_Cleanup(Klaxon* const me);
Klaxon * Klaxon_Create(void);
void Klaxon_Destroy(Klaxon* const me);


void Klaxon_alarmOn(Klaxon* const me);

#endif
