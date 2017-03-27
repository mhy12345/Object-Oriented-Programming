#include "Hen.h"
#include "Nest.h"
#include "Egg.h"
using namespace std;
int main()
{
	Hen hen;
	Hen::Nest nest;
	Hen::Nest::Egg egg;
	hen.display();
	nest.display();
	egg.display();
	return 0;
}
