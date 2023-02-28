#include<iostream>
#include"list.h"
using namespace std;
void test1()
{
	bit::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	bit::list<int>::iterator it = l.begin();
	bit::list <int> a;
	a(l);

}
void test2()
{
	bit::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);

}
int main()
{
	test1();
	return 0;
}