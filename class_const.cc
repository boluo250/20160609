 ///
 /// @file    explicit.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-09 20:06:53
 ///
 
#include <iostream>
#include <string.h> 
using namespace std;

class Point
{
public:
	Point(int x)  //只有一个参数的构造函数要声明显示转换
	//const类型只能在初始化列表进行初始化
	:_ix(x)
	,_p("hell")
	{
	//	strcpy(_brand,brand);
		cout << "explicit Point(int)" << endl;
	//	_ix = x;    // const不可以赋值
	}
	void print()
	{
		cout << "x = " << _ix << endl;
		cout << _p << endl;
	}
private:
	 int _ix;
	 const char *_p;
};

int main()
{
	Point p(4);
	p.print();

	return 0;
}
