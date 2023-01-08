#include<iostream>
using namespace std;
class Date
{
	friend ostream& operator <<(ostream& out, const Date& d);
	friend istream& operator >>(istream& in, Date& d);
public:
	int GetMonthDay(int year, int month);
	void print();
	Date(int year = 1900, int month = 1, int day = 1);
	Date& operator+=(int day);
	Date(const Date& d);
	Date operator+(int day);
	bool operator>(const Date& d);
	bool operator < (const Date& d);
	bool operator <= (const Date& d);
	Date& operator-=(int day);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator != (const Date& d);
	bool operator == (const Date& d);
	int operator-(const Date& d);
	bool operator >= (const Date& d);
	Date operator-(int day);
	Date& operator=(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator <<(ostream& out, const Date& d);
istream& operator >>(istream& in, Date& d);
