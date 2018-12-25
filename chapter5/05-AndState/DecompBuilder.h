#ifndef DecompBuilder_H
#define DecompBuilder_H

typedef struct DecompBuilder DecompBuilder;
struct DecompBuilder
{

};

void DecompBuilder_Init(DecompBuilder* const me);
void DecompBuilder_Cleanup(DecompBuilder* const me);
DecompBuilder * DecompBuilder_Create(void);
void DecompBuilder_Destroy(DecompBuilder* const me);


#endif
