#include "mst.h"
using std::make_pair;
typedef pair<double,pair<int,int> > edge_t;
bool MST::cmp_edge(edge_t e1,
		edge_t e2)
{
	return e1.first<e2.first;
}

int MST::get_fa(int x)
{
	return uf[x] == x ? x : get_fa(uf[x]);
}

double MST::ComputeMST()
{
	vector<edge_t > edge;
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
