#include"mst.h"
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

int main()
{
	MST G;
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<20;j++)
		{
			set<Point> S;
			Point pt(0,0);
		   	do {
				pt = Point(rand()%100,rand()%100);
				if (S.find(pt) == S.end())
					break;
			}while (true);
			S.insert(pt);
			printf("Add Point(%d,%d)...\n",pt.getx(),pt.gety());
			G.AddPoint(pt);
		}
		printf("MST is :%lf\n",G.ComputeMST());
		G.Clear();
	}
}
