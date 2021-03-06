#ifndef MST_H
#define MST_H
#include "graph.h"
#include "tree.h"

class MST:public Graph
{
	private:
		int *uf;
	protected:
		Tree T;
	public:
		MST():T(){}
		int get_fa(int x);
		double ComputeMST();
		static bool cmp_edge(pair<double,pair<int,int> > e1,
				pair<double,pair<int,int> > e2);
};

#endif //MST_H
