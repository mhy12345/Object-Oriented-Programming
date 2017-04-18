#ifndef TREE_H
#define TREE_H
#include<vector>
using std::vector;
using std::pair;

class Tree
{
	private:
		class Edge
		{
			private:
				static int cnt;
			public:
				int id;
				int x,y;
				double z;
				Edge(int x,int y,double z):x(x),y(y),z(z){id=++cnt;}
		};
		vector<Edge> edges;
		int n;
		int *fa,*fid;
		int *depth;
		int *jump[20],*jvalue[20];
		vector<int>* son;
		vector<pair<int,int> >* edge;
	public:
		friend class KMST;
		Tree(){}
		Tree(int n);
		~Tree();
		void Add_Edge(int x,int y,double z);
		void Build_Tree();
		vector<Edge> Get_Path(int x,int y);
		void Clear();
		bool Inside(int x,int y,int z){
			for (int i=0;i<(int)edges.size();i++)
			{
				if (edges[i].x == x && edges[i].y == y && edges[i].z == z)
					return true;
				if (edges[i].x == y && edges[i].y == x && edges[i].z == z)
					return true;
			}
			return false;
		}
};

#endif
