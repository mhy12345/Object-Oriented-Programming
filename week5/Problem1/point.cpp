#include"point.h"
#include<cmath>

double distance(const Point &p1,const Point& p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

bool operator <(const Point &p1,const Point& p2)
{
	if (p1.x!=p2.x)
		return p1.x<p2.x;
	return p1.y<p2.y;
}

