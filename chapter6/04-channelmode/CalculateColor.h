#ifndef CalculateColor_H
#define CalculateColor_H

typedef struct CalculateColor CalculateColor;
struct CalculateColor
{
    int red;
    int green;
    int blue;
};

/* Constructors and destructors:*/
void CalculateColor_Init(CalculateColor* const me);
void CalculateColor_Cleanup(CalculateColor* const me);

/* Operations */

CalculateColor * CalculateColor_Create(void);
void CalculateColor_Destroy(CalculateColor* const me);

void CalculateColor_setItsLightDeviceDriver(CalculateColor* const me, LightDeviceDriver* p_LightDeviceDriver);

#endif
