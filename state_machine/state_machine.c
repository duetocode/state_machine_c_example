#include "_state_machine.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

state_machine_t machine;

static bool in_transition = false;

void machine_init(void)
{
    machine.current_state = &state_powered_off;
    if (machine.current_state->enter != NULL)
        machine.current_state->enter();
}
void machine_state_transite_to(const state_t *state)
{
    // Do nothing if no state change
    if (machine.current_state == state)
    {
        return;
    }

    machine.next_state = state;

    printf("Transite to %s\n", state->name);

    // If we are already in a transition, then no need to invoke the leave hook
    if (in_transition)
    {
        return;
    }

    in_transition = true;
    while (machine.next_state != NULL)
    {
        const state_t *next_state = machine.next_state;
        machine.next_state = NULL;

        if (machine.current_state->leave != NULL)
            machine.current_state->leave();

        machine.current_state = next_state;

        if (machine.current_state->enter != NULL)
            machine.current_state->enter();
    }
    in_transition = false;
}

#define DEFINE_EVENT(EVENT_NAME)                       \
    void machine_##EVENT_NAME(void)                    \
    {                                                  \
        if (machine.current_state->EVENT_NAME != NULL) \
            machine.current_state->EVENT_NAME();       \
    }

DEFINE_EVENT(power_on)
DEFINE_EVENT(start)
DEFINE_EVENT(stop)
DEFINE_EVENT(pause)
DEFINE_EVENT(resume)

const char *machine_get_state(void)
{
    return machine.current_state->name;
}