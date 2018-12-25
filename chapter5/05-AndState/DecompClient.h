
#ifndef DecompClient_H
#define DecompClient_H

typedef struct DecompClient DecompClient;
struct DecompClient
{

};

void DecompClient_Init(DecompClient* const me);
void DecompClient_Cleanup(DecompClient* const me);
DecompClient * DecompClient_Create(void);
void DecompClient_Destroy(DecompClient* const me);


#endif
