 ///
 /// @file    reference.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-09 21:11:15
 ///
 
#include <iostream>
 
using namespace std;

class Point
{
public:
	Point(int ix,int iy,double &dz)
	:_ix(ix)
	,_iy(iy)
	,_ref1(_ix)
	,_ref2(dz)
	{
		cout << "Point(int,int,double)" << endl;
	}
	Point(const Point &rhs)
	:_ix(rhs._ix)
	,_iy(rhs._iy)
	,_ref1(rhs._ref1)
	,_ref2(rhs._ref2)
	{
		cout << "Point(cosnt Point &)" << endl;
	}
	void print()
	{
		cout << _ix << " "
			 << _iy << " "
			 << _ref1 << " "
			 <<_ref2  << endl;
	}
	void setX(int x)
	{
		_ix = x;
	}
private:
	int _ix;
	int _iy;
	int &_ref1;
	double &_ref2;
};

int main()
{
	double dz = 3.1;
	Point p1(1,2,dz);
	p1.print();
	Point p2(p1);
	p2.print();
	p1.setX(10);
	p1.print();
	p2.print();

	return 0;
}
