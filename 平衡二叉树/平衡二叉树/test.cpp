#include"avltree.h"
#include<time.h>
//int a[] = { 16,3,7,11,9,26,18,14,15 };
int a[] = { 4,2,6,1,3,5,15,7,16,14 };

void test1()
{
	avltree<int, int> t1;
	for (auto e : a)
	{
		t1.insert(std::make_pair(e, e));

	}
	t1.inorder();
	std::cout << t1.isbalance() << std::endl;
}
void test2()
{
	avltree<int, int> t1;
	size_t N = 10000;
	srand(time(0));
	for (size_t i = 0; i < N; i++)
	{
		int x = rand();
		t1.insert(std::make_pair(x, i));
	}
}
int main()
{
	test1();
}