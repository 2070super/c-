#include<iostream>
using namespace std;
class person
{
public:
	virtual void buyticket()
	{
		cout << "买票全价" << endl;
	}
};
class person1
{
public:
	virtual void buyticket()
	{
		cout << "买票全价" << endl;
	}
};
class student :public person
{
public:
	virtual void buyticket()//与基类为多态
	{
		cout << "买票半价" << endl;
	}
};
class student1 :public person
{
public:
	void buyticket()//与基类为多态,继承基类的虚函数
	{
		cout << "买票半价" << endl;
	}
};
class student2 :public person1
{
public:
	void buyticket()//隐藏基类的函数。
	{
		cout << "买票半价" << endl;
	}
};
void func(person& people)//(person *people)
//不能用(person people)，这样直接强转成person
{
	people.buyticket();
}
int main()
{
	person people1;
	student people2;
	func(people1);
	func(people2);
	return 0;
}