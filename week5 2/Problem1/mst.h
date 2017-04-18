#ifndef MST_H
#define MST_H
#include "graph.h"

class MST:public Graph
{
	private:
		int *uf;
	public:
		int get_fa(int x);
		static bool cmp_edge(pair<double,pair<int,int> > e1,
				pair<double,pair<int,int> > e2);
		double ComputeMST();
};

#endif //MST_H
