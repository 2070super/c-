#include<iostream>
int main()
{//p0=p2,p1=p3
	int* p0 = (int*)malloc(sizeof(int));
	int* p1 = (int*)malloc(sizeof(int) * 10);
	int* p2 = new int;
	int* p3 = new int[10];
	int* p4 = new int(10);//申请一个int对象，初始化为10
}