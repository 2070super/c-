#pragma warning(disable:4996)
#include"string.h"
using namespace std;
haha::string::string(const char* str)
//:_str(new char[strlen(str)+1])
//,_size(strlen(str))
//,_capacity(strlen(str)) 一般是自定义类型放入初始化列表，内置变量不用。
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
char& haha::string::operator[](size_t t) const
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
size_t haha::string::size() const
{
	return _size;
}
void haha::string::reserve(size_t t)
{
	if (t > _capacity)
	{
		char* tmp = new char[t+1];//new和realloc在内置类型上没有区别，但是new自动捕获异常，realloc不会，但是在自定义类型new支持，realloc不行。另外注意拷贝函数是将\0一起拷贝，需要加1.
		strcpy(tmp, _str);
		delete[]_str;
		_str = tmp;
		_capacity = t;
	}
}
void haha::string::push_back(char ch)
{
	if (_capacity == _size)
		if(_capacity!=0)   
	{
		reserve(2 * _capacity);
	}
		else
		{
			reserve(1);
		}
	_str[_size] = ch;
	_size++;
	_str[_size] = '\0';
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
	:_str(nullptr)//不添加的话运行结束后会将s._str所指向的区域析构了。
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
void haha::string::resize(size_t n, char ch ='\0')
{

	if (n < _size)
	{
		_str[n] = '\0';
		_size = n;
	}
	else
	{
		if (n > _capacity)
		{
			reserve(n);
		}
		for (size_t i = _size; i < n; ++i)
		{
			_str[i] = ch;
		}
		_str[n] = '\0';
	}
}
void haha::string::insert(size_t n,char ch)
{
	assert(n <= _size);
	if (_capacity == _size)
	{
		reserve(2 * _capacity);
	}
	size_t end = _size+1;//无符号整数，加1是为了考虑0的情况
	//while (end >= n)//这里不能改成int，该行比较的时候会出现隐式提升
	while (end > n)
	{
		_str[end + 1] = _str[end];
		end--;
	}
	_str[n] = ch;
	_size++;
}
void haha::string::insert(size_t n, const char* str)
{
	assert(n <= _size);
	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		reserve(_size + len);
	}
	size_t end = _size + len+1;
	while (end >= n+len)
	{
		_str[end-1] = _str[end - len-1];
		--end;
	}

	strncpy(_str + n, str, len);
	_size += len;
}
char* haha::string::c_str(const string& s)
{
	return _str;
}
void haha::string::erase(size_t pos, size_t len=npos)
{
	assert(pos < _size);
	if (len==npos||len + pos >= _size)
	{
		_size = pos;
		_str[pos] = '\0';
	}
	else
	{
		strcpy(_str + pos, _str + pos + len);
		_size -= len;
	}
}
size_t haha::string::find(size_t pos, char ch)
{
	for (size_t i = pos; i < _size; i++)
	{
		if (_str[i] == ch)
		{
			return i;
		}
	}
	return npos;
}
size_t haha::string::find(const char* sub, size_t pos=0)
{
	const char* local = strstr(_str + pos, sub);
	if (local== nullptr)
	{
		return npos;
	}
	else
	{
		return local - _str;
	}
}
bool operator >(const haha::string& s1,const haha::string& s2)
{
	size_t i1 = 0, i2 = 0;
	while (i1 < s1.size() && i2 < s2.size())
	{
		if (s1[i1] > s2[i2])
		{
			return true;
		}
		else if (s1[i1] < s2[i2])
		{
			return false;
		}
		else
		{
			++i1;
			++i2;
		}
	}
	if (i1 < s1.size())
	{
		return true;
	}
	if (i2 < s2.size())
	{
		return false;
	}
	
}
bool operator ==(const haha::string& s1, const haha::string& s2)
{
	if (s1.size() == s2.size())
		return true;
	else
		return false;
}
bool operator <(const haha::string& s1, const haha::string& s2)
{
	if (s1 > s2||s1==s2)
	{
		return false;
	}
	else 
	{
		return true;
	}
}
ostream& operator<< (ostream& out, const haha::string & s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		out << s[i];
	}
	return out;
}
istream& operator>>(istream& in,  haha::string& s)
{
	s.resize(0);//防止出现引用。
	char ch;
	//in>>ch 无法使用，因为in无法插入'\0'
	in.get(ch);
	while (1)

	{
		if (ch == ' ' || ch == '\0')
		{
			break;
		}
		else
		{
			s += ch;
		}
	}
	return in;
}
typedef char* iterator;
haha::string::iterator haha::string::begin()
{
	return _str;
}
haha::string::iterator haha::string::end()
{
	return _str + _size;
}
 haha::string::iterator haha::string::begin() const
{
	return _str;
}
 haha::string::iterator haha::string::end() const
{
	return _str + _size;
}