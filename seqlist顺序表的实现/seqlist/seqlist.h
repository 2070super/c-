#pragma once
typedef int SLDataType;
typedef struct Seqlist
{
	SLDataType* a;
	int size;
	int capacity;
} SL;
void SeqlistInit(SL* ps);
void SeqlistPrint(SL* ps);
void SeqlistCheckcapacity(SL* ps);
void SeqlistDestory(SL* ps);