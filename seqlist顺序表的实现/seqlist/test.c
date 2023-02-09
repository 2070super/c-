#include"seqlist.h"
void test1()
{
	Seqlist a;
	SeqlistInit(&a);
	SeqlistDestory(&a);
	Seqlist s;
	SeqlistInit(&s);
	Seqlistpushback(&s, 1);
	Seqlistpushback(&s, 2);
	Seqlistpushback(&s, 3);
	Seqlistpushback(&s, 4);
	Seqlistpushback(&s, 5);
	Seqlistpushback(&s, 6);
	Seqlistpushback(&s, 7);
	Seqlistpushback(&s, 8);
	SeqlistPrint(&s);
	Seqlistpopback(&s);
	SeqlistPrint(&s);
	Seqlistpushfront(&s, 0);
	SeqlistPrint(&s);
	Seqlislerase(&s,3);
	SeqlistPrint(&s);
	Seqlistinsert(&s, 3, 2);
	SeqlistDestory(&s);
}
int main()
{
	test1();
}