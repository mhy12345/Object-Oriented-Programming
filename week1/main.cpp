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
	double ans1 =  polynomial(argc-2,parms,x);
	printf("Polynomial Answer is : %lf\n", ans1);
	try{
		double ans2 = posynomial(argc-2,parms,x);
		printf("Posynomial Answer is : %lf\n", ans2);
	}catch(std::exception err){
		fprintf(stderr,"An error occured.\n");
	}
	return 0;
}
