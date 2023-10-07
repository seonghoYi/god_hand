#include "secondary_main.h"

void bare_delay(uint32_t ms)
{
	sleep_ms(ms);
}

/*
 * secondary_main_entry() runs core1
 * therefore don't use FreeRTOS functions
 */
void secondary_main_entry(void)
{

    while(true)
    {
        ledToggle(_DEF_LED1);
        bare_delay(1000);
    }
}