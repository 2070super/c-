#include"Date.h"
#include<iostream>
using namespace std;
int main()
{
    Date d1 = Date(2000, 3, 24);//��������
    d1.print();//���ڴ�ӡ
    d1 = d1 - 30;//���ڼ�����
    d1.print();
    d1 = d1 + 50;//���ڼ�����
    d1.print();
    Date d2 = Date(2003, 3, 24);
    int a = d2 - d1;//���ڼ�����
    cout << a << endl;
    d2++;//����
    d2.print();
    Date d3(d1);//����һ����d1��ͬ����
    return 0;
}