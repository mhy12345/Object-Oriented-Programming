#ifndef KMST_H
#define KMST_H
#include "mst.h"

class KMST:MST
{
	public:
		KMST(MST tt):MST(tt){}
		void Get_List()
		{
			for (int i=0;i<(int)list.size();i++)
			{
				for (int j=i+1;j<(int)list.size();j++)
				{
					if (T.Inside(i,j,distance(list[i],list[j])))
						continue;
					vector<Tree::Edge> E = T.Get_Path(i,j);
				}
			}
		}
};


#endif //KMST_H
