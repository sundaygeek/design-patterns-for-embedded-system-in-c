#ifndef ButtonDriver_H
#define ButtonDriver_H


#define LOOPS_PER_MS (1000)
#define DEBOUNCE_TIME (40)

struct Button;
struct MicrowaveEmitter;
struct Timer;

typedef struct ButtonDriver ButtonDriver;
struct ButtonDriver {
    unsigned char oldState;
    unsigned char toggleOn;
    struct Button* itsButton;
    struct MicrowaveEmitter* itsMicrowaveEmitter;
    struct Timer* itsTimer;
};


void ButtonDriver_Init(ButtonDriver* const me);
    void ButtonDriver_Cleanup(ButtonDriver* const me);

/* Operations */
void ButtonDriver_eventReceive(ButtonDriver* const me);
struct Button* ButtonDriver_getItsButton(const ButtonDriver* const me);
void ButtonDriver_setItsButton(ButtonDriver* const me, struct Button* p_Button);

struct MicrowaveEmitter* ButtonDriver_getItsMicrowaveEmitter(const ButtonDriver* const me);
void ButtonDriver_setItsMicrowaveEmitter(ButtonDriver* const me, struct MicrowaveEmitter* p_MicrowaveEmitter);

struct Timer* ButtonDriver_getItsTimer(const ButtonDriver* const me);
void ButtonDriver_setItsTimer(ButtonDriver* const me, struct Timer* p_Timer);

ButtonDriver * ButtonDriver_Create(void);
void ButtonDriver_Destroy(ButtonDriver* const me);

void ButtonDriver_setItsButton2(ButtonDriver* const me, struct Button* p_Button);
void ButtonDriver_setItsButton1(ButtonDriver* const me, struct Button* p_Button);
void ButtonDriver_clearItsButton(ButtonDriver* const me);

#endif
