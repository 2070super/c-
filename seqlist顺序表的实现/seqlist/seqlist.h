#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct Seqlist
{
	SLDataType* a;
	int size;
	int capacity;
} SL,Seqlist;
void SeqlistInit(SL *ps);
void SeqlistPrint(SL* ps);
void SeqlistCheckcapacity(SL* ps);
void SeqlistDestory(SL* ps);
void Seqlistpushback(SL* ps,SLDataType x);
void Seqlistpopback(SL* ps);
void Seqlistpopfront(SL* ps);
void Seqlistpushfront(SL* ps, SLDataType x);
void Seqlistinsert(SL* ps,SLDataType x,int pos);
void Seqlislerase(SL* ps, int pos);