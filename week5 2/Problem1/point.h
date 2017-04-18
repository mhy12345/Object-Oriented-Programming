#ifndef POINT_H_
#define POINT_H_
class Point
{
	private:
		int x,y;
	public:
		Point(int x,int y):x(x),y(y){}
		int getx(){return x;}
		int gety(){return y;}
		friend double distance(const Point &p1,const Point &p2);
		friend bool operator <(const Point &p1,const Point &p2);
};

#endif //POINT_H
