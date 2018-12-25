#ifndef LightDeviceDriver_H
#define LightDeviceDriver_H

typedef struct LightDeviceDriver LightDeviceDriver;
struct LightDeviceDriver
{

};

/* Constructors and destructors:*/
void LightDeviceDriver_Init(LightDeviceDriver* const me);
void LightDeviceDriver_Cleanup(LightDeviceDriver* const me);

/* Operations */

LightDeviceDriver * LightDeviceDriver_Create(void);
void LightDeviceDriver_Destroy(LightDeviceDriver* const me);

#endif
