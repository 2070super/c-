#include<iostream>
int main()
{
	int a = 10;
	int& b = a;
	a = 20;
	b = 30;
	//int& e;���ñ����ʼ��
	int x = 2;
	b = x; 
	return 0;
 }