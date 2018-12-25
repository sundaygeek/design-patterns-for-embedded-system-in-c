#ifndef ButtonHandler_H
#define ButtonHandler_H

typedef void (*ButtonVectorPtr)(void);
struct LED;

extern ButtonVectorPtr oldVectors[10];

/* Operations */
void install(void);
void deinstall(void);

interrupt void handleButtonPushInterrupt(void);
interrupt void handleButtonReleaseInterrupt(void);

struct LED* ButtonHandler_getItsLED(void);
void ButtonHandler_setItsLED(struct LED* p_LED);

#endif
