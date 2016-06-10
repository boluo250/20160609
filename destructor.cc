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
	Computer()
	:_brand(NULL)
	{
		cout << "Computer()" << endl;
	}
	Computer(int x,int y,const char *brand)
	:_ix(x)
	,_iy(y)
	{
		_brand = new char[strlen(brand)+1];
		strcpy(_brand,brand);
		cout << "Computer(int,int)" << endl;
	}
#if 0
	//系统默认提供的不在适用
	Computer(const Computer & rhs)
	:_ix(rhs._ix)
	,_iy(rhs._iy)
	,_brand(rhs._brand)//浅拷贝,传递地址,2个指针指向同一块内存,所以释放会出现错误
	{
		cout << "Computer(const Computer &)" << endl;
	}
#endif
	//Computer pc = com, pc(com);2种都是初始化调用复制构造函数
	//如果参数是对象,在发生复制构造时,会导致无线递归,不停调用自身,直到栈溢出
	//所以参数只能是引用
	Computer(const Computer &rhs)
	:_ix(rhs._ix)
	,_iy(rhs._iy)
	{
		//深拷贝,指针重新指向另一块内存
		_brand = new char[strlen(rhs._brand)+1];
		strcpy(_brand,rhs._brand);
		cout << "Computer(const Computer &)" << endl;
	}

	Computer & operator = (const Computer & rs)
	{
		cout << "Computer & operator" << endl;
		if(this == &rs)
			return *this;
		delete [] _brand;
		_brand = new char[strlen(rs._brand)+1];
		strcpy(_brand,rs._brand);
		_ix = rs._ix;
		_iy = rs._iy;
		return *this;
	}
	//在类里面定义的成员函数都是inline函数
	//inline函数在调用它的地方时直接执行函数体
	//没有函数调用的开销
	void print()
	{
		cout << "x =" << _ix << endl;
		cout     << "y =" << _iy << endl;
		cout <<"brand = " << _brand << endl;
	}
	//对于栈对象而言,创建时自动调用构造函数
	//销毁时,自动调用析构函数
	~Computer()
	{
		delete [] _brand;
		cout << "delete _brand" << endl
		 << "~Computer()" << endl;
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
	Computer pc = com;
	pc.print();
	return 0;
}

