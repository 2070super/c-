#include "heap.h"
//小堆
void Adjustdown(HPDataType* a, int n,int root)
{	
	int parent = root;
	int child = parent * 2 + 1;//leftchild
	while (child < n)
	{
		if(a[child + 1] < a[child]&&child+1<n)//左右孩子比较
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
	free(p->_a);
	p->_a = NULL;
	p->_size = 0;
	p->_capacity = 0;

}

void Heappush(Heap* p, HPDataType x)
{
}

void Heapsort(int* a, int n)//堆排序
{
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		Adjustdown(a, n, i);
	}
}

