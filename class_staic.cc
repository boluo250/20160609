 ///
 /// @file    class_staic.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-09 19:08:36
 ///
 
#include <iostream>
 
using namespace std;

class Point
{
public:
	Point(const float fprice)
	:_price(fprice)
	{
		_Fprice += fprice;
		cout << "Point(const float)" << endl;
	}
	static void print(Point & com)
	{
		cout << "price = " <<com._price << endl
			 << "totalprice = " << _Fprice << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
		_Fprice -= _price;
	}


private:
	float _price;
	static float _Fprice;
};

float Point::_Fprice = 0.0;

int main()
{
	Point pc(100.0);
	pc.print(pc);
	Point pc1(200.0);
	pc1.print(pc1);

	return 0;
}
