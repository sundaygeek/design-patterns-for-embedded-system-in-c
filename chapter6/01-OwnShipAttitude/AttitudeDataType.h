#ifndef AttitudeDataType_H
#define AttitudeDataType_H

#define ATTITUDE_MEMORY_FAULT 0

typedef struct AttitudeDataType AttitudeDataType;
struct AttitudeDataType
{
    int roll;
    int yaw;
    int pitch;
};

void AttitudeDataType_Init(AttitudeDataType* const me);
void AttitudeDataType_Cleanup(AttitudeDataType* const me);
AttitudeDataType* AttitudeDataType_Create(void);
void AttitudeDataType_Destroy(AttitudeDataType* const me);

#endif
