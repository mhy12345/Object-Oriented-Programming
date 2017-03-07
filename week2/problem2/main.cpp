#include "reviewer_assigner.h"
#include "team_assigner.h"

int main()
{
	ReviewerAssigner RA;
	RA.load();
	RA.output();
	TeamAssigner TA;
	TA.load();
	TA.output();
}
