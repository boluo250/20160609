 ///
 /// @file    string.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-09 21:35:18
 ///
 
#include <iostream>
#include <string.h> 
using namespace std;

class String
{
public:
	String()
	{
		_pstr = new char[1];
		cout << "String()" << endl;
	}
	String(const char *pstr)
	{
		_pstr = new char[strlen(pstr)+1];
		strcpy(_pstr,pstr);
		cout << "String(const char *)" << endl;
	}
	String(const String &rhs)
	{
		_pstr = new char[strlen(rhs._pstr)+1];
		strcpy(_pstr,rhs._pstr);
		cout << "String(const String &)" << endl;
	}
	String & operator = (const String & rhs)
	{
		if(this == &rhs)
			return *this;
		delete [] _pstr;
		_pstr = new char[strlen(rhs._pstr)+1];
		strcpy(_pstr,rhs._pstr);
		cout << "String &operator=(const String&)" << endl;
	}
	~String()
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}
	void print()
	{
		cout << _pstr << endl;
	}
private:
	char *_pstr;
};

int main()
{
	String str1;
	str1.print();

	String str2 = "hello,world";
	String str3 = "wangdao";

	str2.print();
	str3.print();
	str2 = str3;
	str2.print();

	String str4 = str3;
	str4.print();

	return 0;
}


