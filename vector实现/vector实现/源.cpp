#include"vector.h"
#include <iostream>
#include"vector.cpp"
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
	while (it == v.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}
int main()
{
	
	test();
	return 0;
}