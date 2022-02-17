#include<iostream>
void test(int a = 10, int b = 20, int c = 30)
{
	std::cout << "a=" << a << std::endl;
	std::cout << "b=" << b << std::endl;
	std::cout << "c=" << c << std::endl;
}



int main()
{
	test();//ȫȱʡ
	test(1);//��ȱʡ
	test(1, 2);
	test(1, 2, 3);
}
