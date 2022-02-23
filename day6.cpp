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

private:
	int _year;
	int _mouth;
	int _day;
};
int main()
{
	date d1;
	d1.init(2000, 3, 24);
	d1.print();
	date d2;
	d2.print();
}
	
	
