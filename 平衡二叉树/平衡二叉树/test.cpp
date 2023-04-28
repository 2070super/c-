#include"avltree.h"
int a[] = { 16,3,7,11,9,26,18,14,15 };
int main()
{
	avltree<int, int> t1;
	for (auto e : a)
	{
		t1.insert(std::make_pair(e, e));
		
	}
	t1.inorder();
}