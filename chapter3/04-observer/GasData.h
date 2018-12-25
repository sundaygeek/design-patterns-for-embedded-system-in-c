#ifndef GasData_H
#define GasData_H

#include <stdio.h>
#include <stdlib.h>

typedef struct GasData GasData;
struct GasData
{
    unsigned short N2Conc;
    unsigned short O2Conc;
    unsigned int flowRate;
};

/* Constructors and destructors:*/
void GasData_Init(GasData* const me);
void GasData_Cleanup(GasData* const me);
GasData * GasData_Create(void);
void GasData_Destroy(GasData* const me);

#endif

