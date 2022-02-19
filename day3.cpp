#include<iostream>
int main()
{
	int a = 10;
	int& b = a;
	a = 20;
	b = 30;
	//int& e;引用必须初始化
	int x = 2;
	b = x; 
	return 0;
 }