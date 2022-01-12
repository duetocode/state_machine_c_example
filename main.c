#include <stdio.h>
#include "state_machine.h"


int main(void)
{
    machine_init();
    printf("State: %s\n", machine_get_state());

    machine_power_on();
    printf("State: %s\n", machine_get_state());
    machine_stop();
    printf("State: %s\n", machine_get_state());
    machine_start();
    printf("State: %s\n", machine_get_state());
    machine_stop();
    printf("State: %s\n", machine_get_state());
    machine_start();
    printf("State: %s\n", machine_get_state());
    machine_pause();
    printf("State: %s\n", machine_get_state());
    machine_resume();
    printf("State: %s\n", machine_get_state());
    machine_stop();
    printf("State: %s\n", machine_get_state());
}