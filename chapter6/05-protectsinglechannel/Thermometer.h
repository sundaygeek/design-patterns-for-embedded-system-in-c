#ifndef Thermometer_H
#define Thermometer_H

struct CheckTemperature;
struct FurnaceController;

typedef struct Thermometer Thermometer;
struct Thermometer {
    int invertedMeasuredTemp;
    int measuredTemp;
    struct CheckTemperature* itsCheckTemperature;
    struct FurnaceController* itsFurnaceController;
};

/* Constructors and destructors:*/

void Thermometer_Init(Thermometer* const me);

void Thermometer_Cleanup(Thermometer* const me);

/* Operations */
void Thermometer_acquireMeasuredTemperature(Thermometer* const me);

int Thermometer_getMeasuredTemperature(Thermometer* const me);

struct CheckTemperature* Thermometer_getItsCheckTemperature(const Thermometer* const me);

void Thermometer_setItsCheckTemperature(Thermometer* const me, struct CheckTemperature* p_CheckTemperature);

struct FurnaceController* Thermometer_getItsFurnaceController(const Thermometer* const me);

void Thermometer_setItsFurnaceController(Thermometer* const me, struct FurnaceController* p_FurnaceController);

Thermometer * Thermometer_Create(void);

void Thermometer_Destroy(Thermometer* const me);

struct CheckTemperature* Thermometer_getItsCheckTemperature_1(const Thermometer* const me);

void Thermometer_setItsCheckTemperature_1(Thermometer* const me, struct CheckTemperature* p_CheckTemperature);

#endif
