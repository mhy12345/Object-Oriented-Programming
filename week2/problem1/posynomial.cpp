#include "func.h"
double posynomial(int n,double *a,double x)
{
	if (x==0)
		throw std::exception();
	double sum=0;
	for (int i=n-1; i>=0; i--)
		sum = sum / x + a[i];
	return sum;
}
double posynomial_slow(int n,double *a,double x)
{
	if (x==0)
		throw std::exception();
	double sum=0;
	for (int i=0;i<n;i++)
	{
		double t=1;
		for (int j=0;j<i;j++)
			t = t/x;
		sum +=  t*a[i];
	}
	return sum;
}
