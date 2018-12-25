#ifndef SmartDataExample_H
#define SmartDataExample_H


struct AlarmManager;
struct PatientDataClass;
struct SmartColor;
struct SmartDataClient;
struct SmartInt;

typedef enum ErrorCodeType {
    NO_ERRORS,
    BELOW_RANGE,
    ABOVE_RANGE,
    INCONSISTENT_VALUE,
    ILLEGAL_USE_OF_NULL_PTR,
    INDEX_OUT_OF_RANGE
} ErrorCodeType;

typedef enum ColorType {
    BLACK,
    BROWN,
    RED,
    PINK,
    BLUE,
    GREEN,
    YELLOW,
    WHITE
} ColorType;

#endif
