#include"func.h"

int main(int argc,const char* args[])
{
	if (argc<=1)
	{
		fprintf(stderr,"Parameters required!");
		return 0;
	}
	double parms[argc];
	for (int i=1;i<argc-1;i++)
		parms[i-1] = atof(args[i]);
	double x = atof(args[argc-1]);
	try{
		double ans1;
		double ans2;
		clock_t start,finish;
		start = clock();
		for (int i=0;i<10000;i++)
			for (int j=0;j<10000;j++)
				ans1 =  polynomial_slow(argc-2,parms,x);
		finish = clock();
		printf("Polynomial Answer is : %lf\n", ans1);
		printf("Running time is : %lu\n",finish - start);
		start = clock();
		for (int i=0;i<10000;i++)
			for (int j=0;j<10000;j++)
				ans2 = posynomial_slow(argc-2,parms,x);
		finish = clock();
		printf("Posynomial Answer is : %lf\n", ans2);
		printf("Running time is : %lu\n",finish - start);
	}catch(std::exception err){
		fprintf(stderr,"An error occured.\n");
	}
	return 0;
}
