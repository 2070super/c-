#include<iostream>
using std::cout;
using std::endl;

class stack {
private:
	int* _a;
	int _size;
	int _capacity;
public:
	void init(int capacity)
	{
		_a = (int*)malloc(sizeof(int) * capacity);
		_size = 0;
		_capacity = capacity;
	}
	~stack()//栈的析构函数 栈一定要清理资源，一定要写析构函数
{
		free(_a);
		_a = nullptr;
		_size = _capacity = 0;
}
};
int main()
{
	stack a;
	a.init(4);

}