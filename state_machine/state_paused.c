#include "_state_machine.h"

static void stop(void)
{
    machine_state_transite_to(&state_stopped);
}

static void resume(void)
{
    machine_state_transite_to(&state_playing);
}

const state_t state_paused = {.name = "Paused", .stop = &stop, .resume = &resume};