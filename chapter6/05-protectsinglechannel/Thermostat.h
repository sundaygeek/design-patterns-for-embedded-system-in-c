#ifndef Thermostat_H
#define Thermostat_H

struct FurnaceController;

typedef struct Thermostat Thermostat;
struct Thermostat {
    int defaultTempSetting;
    int desiredTemp;
    int invertedDefaultTemp;
    int invertedDesiredTemp;
    struct FurnaceController* itsFurnaceController;
};

/* Constructors and destructors:*/
void Thermostat_Init(Thermostat* const me);
void Thermostat_Cleanup(Thermostat* const me);

/* Operations */
int Thermostat_getDesiredTemperature(Thermostat* const me);

void Thermostat_setDesiredTemperature(Thermostat* const me, int temp);

struct FurnaceController* Thermostat_getItsFurnaceController(const Thermostat* const me);

void Thermostat_setItsFurnaceController(Thermostat* const me, struct FurnaceController* p_FurnaceController);

Thermostat * Thermostat_Create(void);

void Thermostat_Destroy(Thermostat* const me);
#endif
