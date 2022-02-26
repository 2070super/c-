#include<iostream>
using namespace std;
class date {
	//ÓÑÔªº¯Êý
	friend ostream& operator <<(ostream & out, const date & d);
public:
	date(int year = 2000,int month=1,int day =1)
	{	
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;

};
ostream& operator<<(ostream& out,const date& d )
	{
		out << d._year << "-" << d._month << "-" << d._day << endl;
		return out;
	}	
int main()
{
	date d1;
	cout << d1;
}