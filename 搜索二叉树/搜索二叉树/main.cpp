#include"BinarySearchTree.h"
#include<iostream>
int main()
{
	BsTree<int> t;
	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	for (auto e : a)
	{
		t.insert(e);
	}
	t.InOrder();
	t.erase(3);
	std::cout << std::endl;
	t.InOrder();
}