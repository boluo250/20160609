 ///
 /// @file    explicit.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-09 20:06:53
 ///
 
#include <iostream>
 
using namespace std;

class Point
{
public:
	//按照默认规定，只有一个参数的构造函数也定义了一个隐式转换，将该构造函数对应数据类型的数据转换为该类对象
	explicit Point(int x)  //只有一个参数的构造函数要声明显示转换
	:_ix(x)
	{
		cout << "explicit Point(int)" << endl;
	}
	void print()
	{
		cout << "x = " << _ix << endl;
	}
private:
	int _ix;
};

int main()
{
	Point p=5;
	p.print();

	return 0;
}
