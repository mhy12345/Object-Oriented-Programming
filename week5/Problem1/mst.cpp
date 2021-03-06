#include "tree.h"
#include "mst.h"
using std::make_pair;
bool MST::cmp_edge(pair<double,pair<int,int> > e1,
		pair<double,pair<int,int> > e2)
{
	return e1.first<e2.first;
}

int MST::get_fa(int x)
{
	return uf[x] == x ? x : get_fa(uf[x]);
}

double MST::ComputeMST()
{
	T.Clear();
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
			T.Add_Edge(edge[i].second.first,edge[i].second.second,edge[i].first);
		}
	}
	T.Build_Tree();
	delete[] uf;
	return ans;
}
