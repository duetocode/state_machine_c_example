#include "_state_machine.h"

static void enter(void)
{
    machine_state_transite_to(&state_stopped);
}

const state_t state_powered_on = {.name = "Powered On", .enter = &enter};