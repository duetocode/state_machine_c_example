#include "_state_machine.h"

static void start(void)
{
    machine_state_transite_to(&state_playing);
}

const state_t state_stopped = {.name = "Stopped", .start = &start };