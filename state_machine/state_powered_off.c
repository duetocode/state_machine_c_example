#include "_state_machine.h"

static void power_on(void)
{
    machine_state_transite_to(&state_powered_on);
}

const state_t state_powered_off = {.name = "Powered Off", .power_on = &power_on};