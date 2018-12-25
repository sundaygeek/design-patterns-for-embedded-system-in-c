#ifndef LightPkg_H
#define LightPkg_H

struct AndStateList;
struct DecompBuilder;
struct DecompClient;
struct ErrorStateClass;
struct Klaxon;
struct Light;
struct LightController;
struct ModeStateClass;
struct Mutex;
struct StateActionSet;

typedef enum HighLevelLightStates {
    NULL_STATE,
    OFF_STATE,
    ON_STATE,
    EMERGENCY_STATE
} HighLevelLightStates;

typedef enum ColorType {
    RED,
    YELLOW,
    GREEN
} ColorType;

typedef enum FlashType {
    STEADY,
    SLOWLY,
    QUICKLY
} FlashType;

typedef enum ErrorStatesType {
    NULL_ERROR_STATE,
    OK_STATE,
    WARNING_STATE,
    ERROR_STATE
} ErrorStatesType;

typedef enum ModeStatesType {
    NULL_MODE_STATE,
    OPERATIONAL_STATE,
    STARTINGUP_STATE,
    SHUTTINGDOWN_STATE
} ModeStatesType;

typedef enum On_State_Regions {
    ERRORSTATUS_ANDSTATE,
    MODE_ANDSTATE
} On_State_Regions;

#define MAX_ANDSTATES 2

/* This action pointer accepts the me object pointer and no other parameters.  */
typedef int (*ActionPtr0)(void*);

/* This action pointer accepts the me object pointer and no other parameters.  */
typedef int (*ActionPtr1)(void*, int);

#endif
