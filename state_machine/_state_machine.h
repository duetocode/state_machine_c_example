#ifndef _STATE_MACHINE_HEADER
#define _STATE_MACHINE_HEADER

#include "state_machine.h"

typedef struct {
    const char *name;
    /* -- hooks -- */
    void (*enter)(void);
    void (*leave)(void);

    /* -- events -- */
    void (*power_on)(void);
    void (*start)(void);
    void (*stop)(void);
    void (*pause)(void);
    void (*resume)(void);

} state_t;

typedef struct {
    const state_t *current_state;
    const state_t *next_state;
} state_machine_t;

void machine_state_transite_to(const state_t *next_state);

extern state_machine_t machine;

extern const state_t state_powered_off;
extern const state_t state_powered_on;
extern const state_t state_stopped;
extern const state_t state_playing;
extern const state_t state_paused;

#endif