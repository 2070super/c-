#pragma warning(disable:4996)
#include"string.h"
using namespace std;
<<<<<<< HEAD
haha::string::string(const char* str="")
=======
haha::string::string()
	:_str(new char[1])//string s;
{
	_str[0] = '\0';
}
haha::string::string(const char* str)
>>>>>>> 73c5ae3cda9e37236eb72425895be945300cd90f
//:_str(new char[strlen(str)+1])
//,_size(strlen(str))
//,_capacity(strlen(str)) һ�����Զ������ͷ����ʼ���б����ñ������á�
{
	_size = strlen(str);
	_capacity = _size;
	_str = new char[_capacity + 1];
	strcpy(_str, str);
}
haha::string::~string()
{
	delete[] _str;
	_str = nullptr;
	_size = _capacity = 0; 
}
char& haha::string::operator[](size_t t)
{
	assert(t < _size);
	return _str[t];
}
 //haha::string::iterator begin()
//{
	//return haha::string::_str;
//}
size_t haha::string::size()
{
	return _size;
}
void haha::string::reserve(size_t t)
{
	if (t > _capacity)
	{
		char* tmp = new char[t];//new��realloc������������û�����𣬵���new�Զ������쳣��realloc���ᣬ�������Զ�������new֧�֣�realloc���С�
		strcpy(tmp, _str);
		delete[]_str;
		_str = tmp;
		_capacity = t;
	}
}
void haha::string::push_back(char ch)
{
	if (_capacity == _size)
	{
		reserve(2 * _capacity);
	}
	_str[_size] = ch;
	_size++;
}
void haha::string::append(const char* ch)
{
	size_t len = strlen(ch);
	if (_size + len > _capacity)
	{
		reserve(_size + len);
	}
	strcpy(_str + _size, ch);
	_size += len;
}
haha::string& haha::string::operator+=(char ch)
{
	push_back(ch);
	return *this;
}
haha::string& haha::string::operator+=(const char* ch)
{
	append(ch);
	return *this;
}
haha::string& haha::string::operator+=(const string& ch)
{
	append(ch._str);
	return *this;
}
<<<<<<< HEAD
//s1(s2)
=======
>>>>>>> 73c5ae3cda9e37236eb72425895be945300cd90f
haha::string::string(const string& s)
	:_str(nullptr)//����ӵĻ����н�����Ὣs._str��ָ������������ˡ�
{
	string tmp(s._str);
<<<<<<< HEAD
	swap(_str, tmp._str);
}
//s1=s3
haha::string& haha::string::operator=(const string& s)
{
	string tmp( );
=======
	swap(_str, s._str);
}
void haha::string::swap(char* a, char* b)
{
	char* tmp;
	tmp = a;
	a = b;
	b = a;
>>>>>>> 73c5ae3cda9e37236eb72425895be945300cd90f
}