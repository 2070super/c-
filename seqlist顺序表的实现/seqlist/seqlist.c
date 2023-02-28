#include "seqlist.h"

void SeqlistInit(SL *ps)
{
	ps->size = 0;
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("ÉêÇëÊ§°Ü");
		exit(-1);
	}
	ps->capacity = 4;
}

void SeqlistPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d", ps->a[i]);
	}
	printf("\n");
}

void SeqlistCheckcapacity(SL* ps)
{
	if (ps->size >= ps->capacity)
	{	
		ps->capacity = 2 * ps->capacity;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("À©ÈÝÊ§°Ü");
			exit(-1);
		}
	}	
}

void SeqlistDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void Seqlistpushback(SL* ps, SLDataType x)
{
	assert(ps);
	SeqlistCheckcapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void Seqlistpopback(SL* ps)
{
	assert(ps);
	ps->size--;
}

void Seqlistpopfront(SL* ps)
{
	int start = 0;
	while (start<=ps->size-2)
	{
		ps->a[start] = ps->a[start+1];
		start++;
	}
	ps->size--;
}

void Seqlistpushfront(SL* ps, SLDataType x)
{
	SeqlistCheckcapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}

void Seqlistinsert(SL* ps, SLDataType x, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	SeqlistCheckcapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void Seqlislerase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	int start = pos;
	while (start < ps->size - 2)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}
