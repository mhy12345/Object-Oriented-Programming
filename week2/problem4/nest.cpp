#include "nest.h"
#include <cstdio>

Nest::Nest()
{
}

void Nest::display()
{
	printf("This is an nest...\n");
	printf("And I have a egg: \n");
	egg.display();
}
