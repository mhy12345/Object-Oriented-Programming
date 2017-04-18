#include"graph.h"
using namespace std;

void Graph::Clear()
{
	list.clear();
}

void Graph::AddPoint(const Point &pt)
{
	list.push_back(pt);
}


