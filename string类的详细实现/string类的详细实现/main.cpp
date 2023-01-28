#include"string.h"
int main()
{
	haha::string s1("hello");
	haha::string s2(s1);
	haha::string s3 = s1;
	std::swap(s1, s2);//两次构造深拷贝，代价很大。
	s1.swap(s2);
	s1[1] = 's';
	s1.print();
}	