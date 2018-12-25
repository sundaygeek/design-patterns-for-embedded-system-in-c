#ifndef ConvertToFrequency_H
#define ConvertToFrequency_H

typedef struct ConvertToFrequency ConvertToFrequency;
struct ConvertToFrequency
{

};

/* Constructors and destructors:*/
void ConvertToFrequency_Init(ConvertToFrequency* const me);
void ConvertToFrequency_Cleanup(ConvertToFrequency* const me);

/* Operations */

ConvertToFrequency * ConvertToFrequency_Create(void);
void ConvertToFrequency_Destroy(ConvertToFrequency* const me);

void ConvertToFrequency_setItsMovingAverageFilter(ConvertToFrequency* const me, MovingAverageFilter* const p_MovingAverageFilter);

#endif
