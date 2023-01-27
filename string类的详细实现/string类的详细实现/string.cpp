#pragma warning(disable:4996)
#include"string.h"
using namespace std;
haha::string::string(const char* str="")
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
		char* tmp = new char[t+1];//new��realloc������������û�����𣬵���new�Զ������쳣��realloc���ᣬ�������Զ�������new֧�֣�realloc���С�����ע�⿽�������ǽ���0һ�𿽱�����Ҫ��1.
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
	_str[_size] = '\0';//��
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
//s1(s2)
haha::string::string(const string& s)
	:_str(nullptr)//����ӵĻ����н�����Ὣs._str��ָ������������ˡ�
	,_capacity(0)
	,_size(0)
{
	string tmp(s._str);
	swap(tmp);//this->swap(tmp);
	//std::swap(_str, tmp._str);
	//std::swap(_size, tmp._size);
	//std::swap(_capacity, tmp._capacity);
}
//s1=s3
haha::string& haha::string::operator=(const string& s)
{
	if (this != &s)
	{
		string tmp(s._str);
		swap(tmp);
	}
	return *this;
}
void haha::string::swap( string& s)
{
	std::swap(_str, s._str);
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
}
void haha::string::print()
{
	auto it = begin();
	while (it != end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}
