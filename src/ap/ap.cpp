#include "ap.h"


void apInit()
{
	uartOpen(_DEF_UART1, 38400);

}

void apMain()
{

	vTaskStartScheduler();

	while(1)	
	{
	}

/*
 * must not be reached here
 */
}