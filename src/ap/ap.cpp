#include <pico/multicore.h>

#include "ap.h"
#include "secondary_main.h"


void apInit()
{
	uartOpen(_DEF_UART1, 38400);

}

void apMain()
{
	multicore_launch_core1(secondary_main_entry);

	vTaskStartScheduler();

	while(1)	
	{
	}

/*
 * must not be reached here
 */
}