#ifndef STATE_MACHINE_HEADER
#define STATE_MACHINE_HEADER


#define DECLARE_EVENT(EVENT_NAME) void machine_##EVENT_NAME(void);

DECLARE_EVENT(power_on)
DECLARE_EVENT(start)
DECLARE_EVENT(stop)
DECLARE_EVENT(pause)
DECLARE_EVENT(resume)

void machine_init(void);

const char *machine_get_state(void);

#endif