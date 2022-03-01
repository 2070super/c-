#include<iostream>
using namespace std;
class date;//提前声明, time里的友元函数没有date的声明
class Time
{
	friend ostream& operator <<(ostream& out, const date& d);
	friend class date;
public:
Time(int hour=0 , int min=0, int sec=0)
	{
	_sec = sec;
	_min = min;
	_hour = hour;

	}
private:
	int _hour;
	int _min;
	int _sec;
};
class date {
	
	//友元函数
friend ostream& operator <<(ostream & out, const date & d);
public:
	date(int year = 2000, int month = 1, int day = 1, int hour = 0, int min = 0, int sec = 0)
		:_t(hour, min, sec)
	{	
		_year = year;
		_month = month;
		_day = day;
		
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;

};
ostream& operator<<(ostream& out,const date& d )
	{
		out << d._year << "-" << d._month << "-" << d._day << endl;
		out << d._t._hour << d._t._min << d._t._sec << endl;
			return out;
	}	
int main()
{
	date d1;
	cout << d1;//注意这里
}