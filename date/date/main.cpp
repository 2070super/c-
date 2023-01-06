#include"Date.h"
#include<iostream>
using namespace std;
int main()
{
    Date d1 = Date(2000, 3, 24);//定义日期
    d1.print();//日期打印
    d1 = d1 - 30;//日期减天数
    d1.print();
    d1 = d1 + 50;//日期加天数
    d1.print();
    Date d2 = Date(2003, 3, 24);
    int a = d2 - d1;//日期减日期
    cout << a << endl;
    d2++;//自增
    d2.print();
    Date d3(d1);//构造一个与d1相同的类
    return 0;
}