#include<iostream>
int& count()//Ч�ʸ�
{
	static int n = 0;
	n++;
	return n;
}
int main()
{
	int ret = count();
	printf("%d\n", ret);
}