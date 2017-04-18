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
	protected:
		vector<Point> list;
	public:
		void set_list(vector<Point> list) {
			this->list = list;
		}
		void AddPoint(const Point &pt);
		void Clear();
};
#endif //GRAPH_H
