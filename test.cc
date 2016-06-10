 ///
 /// @file    test.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-09 20:57:54
 ///
 
#include <iostream>
 
using namespace std;

int main()
{
	int a = 5;
	int &b = a;
	cout << "b=" << b << endl;
	int &c = b;
	cout << "c=" << c << endl;
	a = 4;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	return 0;
}
