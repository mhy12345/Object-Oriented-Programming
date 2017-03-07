#include "hen.h"
#include <cstdio>

Hen::Hen()
{
}

void Hen::display()
{
	printf("This is an hen...\n");
	printf("And I have a nest: \n");
	nest.display();
}
