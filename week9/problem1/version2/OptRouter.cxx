//////////////////////////////////////////////////////////////////////////
// Description: this is the base implementation of a simple maze router
// Author: mhy12345
// Date: 20170502
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstdio>
#include <queue>
#include <cassert>
#include "OptRouter.h"
using namespace std;

const int mov[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

OptRouter::OptRouter(int r,int c,const Point& source,const Point& target,const PointVector &obs)
	: BaseRouter(r, c, source, target, obs)
{
	//initialize the m_grids with a big value
	this -> m_grids.assign(this->m_col*this->m_row*4,
			make_pair(this->m_col*this->m_row+1,0));


	//if the grids cannot go throught, make the value be -1
	for (int i=0;i<(int)obs.size();i++)
		for (int j=0;j<4;j++)
		{
			//cout<<i<<" "<<j<<" "<<this->compIndex(obs[i].x(),obs[i].y(),j)<<endl;
			this->m_grids[this->compIndex(obs[i].x(),obs[i].y(),j)] = make_pair(-1,0);
		}
}

bool OptRouter::mazeSearch()
{
	//breadth first search
	queue<int> Q;
	vector<bool> in_queue;
	in_queue.assign(m_grids.size(),0);
	for (int i=0;i<(int)m_grids.size();i++)
	{
		if (m_grids[i].first == 0)
			Q.push(i),in_queue[i] = true;
	}
	while (!Q.empty())
	{
		int pos = Q.front();
		Q.pop();
		in_queue[pos] = false;
		int x,y,d;
		this -> compXYIndex(pos,x,y,d);
		printf("Searching (%d,%d,%d) Values (%d,%d)\n",x,y,d,m_grids[pos].first,m_grids[pos].second);
		for (int i=0;i<4;i++)//Direction to enter the next point
		{
			int xx = x+mov[i][0];
			int yy = y+mov[i][1];
			if (!this->valid(xx,yy))continue;
			int npos = this->compIndex(xx,yy,i);
			if (m_grids[npos].first == -1)continue;
			pair<int,int> nval = make_pair(m_grids[pos].first+1,m_grids[pos].second+(d!=i));
			if (m_grids[npos] > nval)
			{
				m_grids[npos] = nval;
				if (!in_queue[npos])
					in_queue[npos] = true;
				Q.push(npos);
			}
		}
	}
	if (m_grids[m_targetIndex*4].first!=m_col*m_row+1
			&& m_grids[m_targetIndex*4].first!=-1)
		return true;
	return false;
}
void OptRouter::mazeBacktrace()
{
	pair<int,int> bstans = make_pair(m_row*m_col+1,1);
	int bstid = -1;
	for (int i=0;i<4;i++)
	{
		if (m_grids[m_targetIndex*4+i] < bstans)
		{
			bstans = m_grids[m_targetIndex];
			bstid = m_targetIndex*4+i;
		}
	}
	//backtrace from the target
	int cpos = bstid;
	while (true)
	{
		m_path.push_back(cpos);
		if (cpos/4 == m_sourceIndex)break;
		int x,y,d;
		this->compXYIndex(cpos,x,y,d);
		x-= mov[d][0];
		y-= mov[d][1];
		bool flag = false;
		for (int i=0;i<4;i++)
		{
			int t = this->compIndex(x,y,i);
			if (m_grids[t].first + 1 == m_grids[cpos].first &&
					m_grids[t].second + (i!=d) == m_grids[cpos].second)
			{
				cpos = t;
				flag = true;
				break;
			}
		}
		assert(flag);
	}
	printf("Path found!\n");
	for (int i=m_path.size()-1;i>=0;i--)
	{
		int x,y,d;
		this->compXYIndex(m_path[i],x,y,d);
		printf("(%d,%d,%d):(%d,%d)\n",x,y,d,m_grids[m_path[i]].first,m_grids[m_path[i]].second);
	}
}
bool OptRouter::route(void)
{
	if (this->m_sourceIndex < 0 || this->m_targetIndex < 0 || this->m_row <= 0 || this->m_col <= 0)
		return false;

	this->m_path.clear();

	//initialize the cost of the source grid
	for (int i=0;i<4;i++)
		this->m_grids[m_sourceIndex*4+i] = make_pair(0,0);

    //maze expansion
	if (mazeSearch())
	{
		mazeBacktrace();
		return true;
	}
	else
		return false;
}
void OptRouter::compXYIndex(int index,int &x,int &y,int &d)
{
	d = index%4;
	BaseRouter::compXYIndex(index/4,x,y);
}
int OptRouter::compIndex(int x,int y,int d)
{
	return BaseRouter::compIndex(x,y)*4+d;
}
bool OptRouter::valid(int x,int y)
{
	return x>=0 && y>=0 && x<m_col && y<m_row;
}
