#include "main.h"



static void threadMain(void *arg);

int main()
{
	bspInit();
	hwInit();
	apInit();

	apMain();
	
	return 0;
}