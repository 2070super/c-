#include "heap.h"
//小堆
void Adjustdown(HPDataType* a, int n,int root)
{	
	int parent = root;
	int child = parent * 2 + 1;//leftchild
	while (child < n)
	{
		if(a[child + 1] < a[child])//左右孩子比较
		{
			child++;
		}
		if (a[parent] > a[child])//交换父子
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	
}

void swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;;
}

void Heapinit(Heap* p, HPDataType* a, int n)
{
	p->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	memcpy(p->_a, a, sizeof(HPDataType) * n);
	p->_size = n;
	p->_capacity = n;
	//堆的构建
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		Adjustdown(p->_a, p->_size, i);
	}
}

void HeapDestory(Heap* p)
{
}

void Heappush(Heap* p, HPDataType x)
{
}

