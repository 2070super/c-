#include<iostream>
using std::cout;
using std::endl;
class date
{
public:
	void init(int year, int month, int day)
	{
		this->_year = year;
		this->_mouth = month;
		this->_day = day;


	}
	void print() {
		cout << _year << "-" << _mouth << "-" << _day << endl;
	}
	~date()
	{
		cout << "清理" << endl;

		//析构函数，清理空间，date由编译器在其生命周期结束后自动释放。
	}
private:
	int _year;
	int _mouth;
	int _day;
	
};

int main()
{
	date d;
	
}