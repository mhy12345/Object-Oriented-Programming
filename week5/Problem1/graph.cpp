#include"graph.h"
using namespace std;

bool Graph::cmp_edge(pair<double,pair<int,int> > e1,
		pair<double,pair<int,int> > e2)
{
	return e1.first<e2.first;
}

int Graph::get_fa(int x)
{
	return uf[x] == x ? x : get_fa(uf[x]);
}

void Graph::Clear()
{
	list.clear();
}

void Graph::AddPoint(const Point &pt)
{
	list.push_back(pt);
}

double Graph::Kruskal()
{
	vector<pair<double,pair<int,int> > > edge;
	for (int i=0;i<(int)list.size();i++)
		for (int j=0;j<(int)list.size();j++)
			edge.push_back(make_pair(distance(list[i],list[j]),make_pair(i,j)));
	sort(edge.begin(),edge.end(),cmp_edge);
	uf = new int[list.size()];
	for (int i=0;i<(int)list.size();i++)
		uf[i] = i;
	double ans = 0;
	for (int i=0;i<(int)edge.size();i++)
	{
		int x = edge[i].second.first;
		int y = edge[i].second.second;
		if (get_fa(x) != get_fa(y))
		{
			uf[get_fa(x)] = get_fa(y);
			ans += edge[i].first;
		}
	}
	delete[] uf;
	return ans;
}

