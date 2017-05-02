//////////////////////////////////////////////////////////////////////////
// Description: this is the base implementation of a simple maze router
// Author: YHL
// Date: 20120323
// Note: Modify this file and add OptRouter.cpp file for the
//       implementation of the additional functionalities
//////////////////////////////////////////////////////////////////////////
#ifndef OPT_ROUTER_H_
#define OPT_ROUTER_H_
#include "BaseRouter.h"

class OptRouter:public BaseRouter
{
public:
    OptRouter(int r, int c, const Point &source, const Point &target, const PointVector &obs);
	~OptRouter() {}
	bool mazeSearch();
	void mazeBacktrace();
	bool route();
	vector<pair<int,int> > m_grids;
	int compIndex(int x,int y);
	int compIndex(int x,int y,int d);
	void compXYIndex(int index,int &x,int &y);
	void compXYIndex(int index,int &x,int &y,int &d);
	bool valid(int x,int y);
};

#endif
