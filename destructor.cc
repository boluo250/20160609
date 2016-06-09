 ///
 /// @file    destructor.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-09 14:17:53
 ///
 
#include <iostream>
#include <string.h> 
using namespace std;


class Computer
{
public:
	Computer(int x,int y,const char *brand)
	:_ix(x)
	,_iy(y)
	{
		_brand = new char[strlen(brand)+1];
		strcpy(_brand,brand);
		cout << "Computer(int,int)" << endl;
	}
	void print()
	{
		cout << "x =" << _ix << endl;
		cout     << "y =" << _iy << endl;
		cout <<"brand = " << _brand << endl;
	}
	~Computer()
	{
		delete [] _brand;
		cout << "delete _brand" << endl;
		cout << "~Computer()" << endl;
	}
private:
	char *_brand;
	int _ix;
	int _iy;
};

int main()
{
	Computer com(3,4,"mac");
	com.print();
	return 0;
}
