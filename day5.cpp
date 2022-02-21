#include<iostream>
class unit
{
private:
	int a1;
	int a2;
public:
	void init(int a, int b)
	{
		a1 = a;
		a2 = b;
	}
};
int main()
{
	unit aa;
	aa.init(3, 4);
	//aa.a1;无法调用
	return 0;
}  