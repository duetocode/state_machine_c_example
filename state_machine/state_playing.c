#include "_state_machine.h"

static void stop(void)
{
    machine_state_transite_to(&state_stopped);
}

static void pause(void)
{
    machine_state_transite_to(&state_paused);
}

const state_t state_playing = {.name = "Playing", .stop = &stop, .pause = &pause};