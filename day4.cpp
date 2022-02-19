#include<iostream>
int& count()//Ğ§ÂÊ¸ß
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