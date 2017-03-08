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
		clock_t time1,time2,time3,time4;
		printf("The original methods...\n");
		start = clock();
		for (int i=0;i<10000;i++)
			for (int j=0;j<10000;j++)
				ans1 =  polynomial_slow(argc-2,parms,x);
		finish = clock();
		printf("Polynomial Answer is : %lf\n", ans1);
		printf("Running time is : %lu\n",time1 = finish - start);
		start = clock();
		for (int i=0;i<10000;i++)
			for (int j=0;j<10000;j++)
				ans2 = posynomial_slow(argc-2,parms,x);
		finish = clock();
		printf("Posynomial Answer is : %lf\n", ans2);
		printf("Running time is : %lu\n",time2 = finish - start);

		printf("The Qingjiushao methods...\n");
		start = clock();
		for (int i=0;i<10000;i++)
			for (int j=0;j<10000;j++)
				ans1 =  polynomial(argc-2,parms,x);
		finish = clock();
		printf("Polynomial Answer is : %lf\n", ans1);
		printf("Running time is : %lu\n",time3 = finish - start);
		start = clock();
		for (int i=0;i<10000;i++)
			for (int j=0;j<10000;j++)
				ans2 = posynomial(argc-2,parms,x);
		finish = clock();
		printf("Posynomial Answer is : %lf\n", ans2);
		printf("Running time is : %lu\n",time4 = finish - start);

		printf("Value imp = %lf,%lf\n",1.0*(time1-time3)/time1,1.0*(time2-time4)/time2);
	}catch(std::exception err){
		fprintf(stderr,"An error occured.\n");
	}
	return 0;
}
