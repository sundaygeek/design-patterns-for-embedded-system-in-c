#ifndef CRCExample_H
#define CRCExample_H

struct AlarmManager;
struct BloodO2Sensor;
struct CRCBuilderClass;
struct CRCClient2;
struct DrugDeliverySystem;
struct HositalPatientSystem;
struct NIBP;
struct PatientData;
struct Thermometer;

typedef enum ErrorCodeType {
    NO_ERRORS,
    UNKNOWN_ERROR,
    CORRUPT_DATA,
    WEIGHT_TOO_LOW,
    WEIGHT_TOO_HIGH,
    AGE_TOO_HIGH,
    GENDER_OUT_OF_RANGE,
    SYSTOLIC_TOO_LOW,
    SYSTOLIC_TOO_HIGH,
    DIASTOLIC_TOO_LOW,
    DIASTOLIC_TOO_HIGH,
    TEMPERATURE_TOO_LOW,
    TEMPERATIURE_TOO_HIGH,
    BLOOD_O2_TOO_LOW,
    BLOOD_O2_TOO_HIGH
} ErrorCodeType;

typedef enum GenderType {
    MALE,
    FEMALE,
    HERMAPHRODITE
} GenderType;

typedef struct PatientDataType {
    unsigned short age;
    unsigned short bloodO2Conc;
    unsigned short diastolicBP;
    GenderType gender;
    unsigned short heartRate;
    char name[100];
    unsigned long patientID;
    unsigned short systolicBP;
    unsigned short temperature;
    double weight;
} PatientDataType;

#endif
