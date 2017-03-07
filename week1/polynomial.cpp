#include "func.h"
double polynomial(int n,double *a,double x)
{
	double sum=0;
	for (int i=n-1; i>=0; i--)
		sum = sum * x + a[i];
	return sum;
}
