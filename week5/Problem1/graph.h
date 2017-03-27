#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include"point.h"
using std::vector;
using std::pair;
class Graph
{
	private:
		vector<Point> list;
		int *uf;
	public:
		void set_list(vector<Point> list)
		{
			this->list = list;
		}
		void AddPoint(const Point &pt);
		void Clear();
		double Kruskal();
		int get_fa(int x);
		static bool cmp_edge(pair<double,pair<int,int> > e1,
				pair<double,pair<int,int> > e2);
};
#endif //GRAPH_H
