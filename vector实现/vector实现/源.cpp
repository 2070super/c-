#include"vector.h"
#include <iostream>
#include"vector.cpp"
using namespace std;
void test()
{
	bit::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] *= 2;
		std::cout << v[i] << std::endl;
	}
	bit::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << std::endl;
		it++;
		auto it = std::find(v.begin(), v.end(), 3);
		v.insert(it, 30);
	}
}
void test1()
{
	bit::vector<int> v(3, 2);
	v.resize(8);
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
	
}
void test2()
{
	bit::vector<string> v;
	v.push_back("1111");
	v.push_back("1111");
	v.push_back("1111");
	v.push_back("1111");
	v.push_back("1111");
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
}
int main()
{
	
	test2();
	return 0;
}