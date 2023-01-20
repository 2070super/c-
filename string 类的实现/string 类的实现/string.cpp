#include<iostream>
#pragma warning(disable:4996)
using namespace std;
namespace haha {
	class string
	{
		public:
		string()
		:_str(new char[1])//string s;
		{
			_str[0] = '\0';
		}
		string(char* str)//string s2('abc');
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}
		char& operator[](size_t i)//s[0]
		{
			return _str[i];
		}
		~string()
		{
			delete[] _str;
		}
		 char* c_str()
		{
			return _str;
		}
		 //s2£¨s1£©
		 string(const string& s)//s2(s1)
			 :_str(new char[strlen(s._str) + 1])
		 {
			 strcpy(_str, s._str);
		 }
		 string& operator =(const string& s)
		 {
			 if (this != &s)
			 {
				 delete[]_str;
				 _str = (new char[strlen(s._str) + 1]);
				 strcpy(_str, s._str);
				 
			 }
			 return *this;
		 }
		private:
		char* _str;
	};
}
int main()
{
	haha::string s3;
	cout << s3.c_str() << endl;
	cout << s3.c_str() << endl;
	haha::string s4 = s3;
	cout << s4.c_str() << endl;
}