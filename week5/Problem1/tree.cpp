#include "tree.h"
using std::pair;
using std::make_pair;
using std::vector;

int Tree::Edge::cnt = 0;

Tree::Tree(int n)
{
	this -> n = n;
	fa = new int[n];
	fid = new int[n];
	depth = new int[n];
	edge = new vector<pair<int,int> >[n];
	son = new vector<int>[n];
	for (int i=0;i<20;i++)
	{
		jump[i] = new int[n];
		jvalue[i] = new int[n];
	}
}
Tree::~Tree()
{
	delete[] fa;
	delete[] fid;
	delete[] depth;
	delete[] edge;
	delete[] son;
	for (int i=0;i<20;i++)
	{
		delete[] jump[i];
		delete[] jvalue[i];
	}
}

void Tree::Add_Edge(int x,int y,double z)
{
	edges.push_back(Edge(x,y,z));
}

void Tree::Build_Tree()
{
	for (int i=0;i<(int)edges.size();i++)
	{
		edge[edges[i].x].push_back(make_pair(edges[i].y,i));
		edge[edges[i].y].push_back(make_pair(edges[i].x,i));
	}
	int q[n];
	q[0] = 0;
	fa[0] = -1;
	int head=-1,tail=0;
	while (head<tail)
	{
		int now = q[++head];
		for (int i=0;i<(int)edge[now].size();i++)
		{
			if (edge[now][i].first == fa[i])
				continue;
			fa[edge[now][i].first] = i;
			fid[edge[now][i].first] = edge[now][i].second;
			depth[edge[now][i].first] = depth[i] + 1;
		}
	}
}
vector<Tree::Edge> Tree::Get_Path(int x,int y)
{
	vector<Tree::Edge> res;
	if (depth[x]<depth[y])std::swap(x,y);
	for (int i=0;i<depth[x]-depth[y];i++)
		res.push_back(edges[fid[x]]),x=fa[x];
	while (fa[x]!=fa[y])
	{
		res.push_back(edges[fid[x]]);x=fa[x];
		res.push_back(edges[fid[y]]);y=fa[y];
	}
	return res;
}

void Tree::Clear()
{
	edges.clear();
	for (int i=0;i<n;i++)
	{
		son[i].clear();
		edge[i].clear();
	}
}
