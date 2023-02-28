#pragma once
typedef int HPDataType;
#include<stdio.h>
#include<string.h>
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}heap,Heap;
void Adjustdown(HPDataType* a, int n,int root);
void swap(HPDataType* p1, HPDataType* p2);
void Heapinit(struct Heap* p,HPDataType *a,int n);
void HeapDestory(struct Heap* p);
void Heappush(struct Heap* p,HPDataType x);
void Heapsort(int* a, int n);