 ///
 /// @file    line.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-09 19:55:17
 ///
 
#include <iostream>
 
using namespace std;

class Point
{
public:
	Point(){}
	Point(int ix,int iy)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}
	void print()
	{
		cout << "(" << _ix << "," 
			 << _iy << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

class Line
{
public:
	Line(int x1,int y1,int x2,int y2)
	:_pt1(x1,y1)
	,_pt2(x2,y2)
	{
		cout << "Line(int,int,int,int)" << endl;
	}
	void print()
	{
		_pt1.print();
		_pt2.print();
	}
private:
	Point _pt1;
	Point _pt2;
};

int main()
{
	Line l(1,2,3,4);
	l.print();

	return 0;
}
