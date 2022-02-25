#include<iostream>
using namespace std;
class date {
public:	
	date(int year = 2000, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void print()
	{
		std::cout << _year << "." << _month << "." << _day<<std::endl;
	}
	date(date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	date operator =(const date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	bool operator==(date d)//bool d1.operator==d2
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	bool operator<(const date& d)
	{
		if (_year >d. _year)
			return true;
		else if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
			}
		}
		return false;
	}
private:
	int _day;
	int _month;
	int _year;

};

int main()
{
	date d1(2022, 1, 1);
	d1.print();
	date d2(d1);
	d2.print();
	d1 < d2;//×Ô¶¨Òå·ûºÅ
	return 0;
}
	
	
