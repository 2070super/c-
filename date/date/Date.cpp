#include"Date.h"
	// 获取某年某月的天数
	int Date::GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}

	// 全缺省的构造函数
	Date::Date(int year, int month , int day )
	{
		if (year >= 0 && month > 0 && month < 13 && day>0 && day < GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
			cout << "日期非法" << endl;
	}
	// 拷贝构造函数
	// d2(d1)
	Date::Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// 赋值运算符重载
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& Date::operator=(const Date& d)
	{
		if(this!=&d)//解决d2=d2
		{
		_year = d._year;
		_month = d._month;
		_day = d._day; 
		}
		return *this;//解决d1=d2=d3
	}
	// 析构函数由编译器解决
	// 日期+=天数
	Date& Date::operator+=(int day)
	{
		if (day < 0)
			return *this -= -day;
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year,_month);
			_month++;
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
		}
		return  *this;
	}
	// 日期+天数
	Date Date::operator+(int day)
	{
		Date ret(*this);
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;
			if (ret._month == 13)
			{
				ret._month = 1;
				ret._year++;
			}
		}
		return ret;
	}
	// 日期-天数
	Date Date::operator-(int day)
	{
		Date ret(*this);
		while (day > ret._day)
		{
			if (ret._month == 1&&ret._year!=0)
			{
				ret._month = 12;
				ret._year--;
			}
			ret._day += GetMonthDay(ret._year, ret._month - 1);
			ret._month--;
		}
		ret._day -= day;
		return ret;
	}
	
		// 日期-=天数
	Date& Date::operator-=(int day)
	{
		while(day > _day)
		{
			if (_month == 1 && _year != 0)
			{
				_month = 12;
				_year--;
			}
			_day += GetMonthDay(_year, _month - 1);
			_month--;
		}
		_day -= day;
		return *this;
	}
	// 前置++
	Date& Date::operator++()
	{
		*this += 1;
		return *this;
	}
	// 后置++
	Date Date::operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}
	// 后置--
	Date Date::operator--(int)
	{
		*this -= 1;
		return *this;
	}
	// 前置--
	Date& Date::operator--()
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}

	// >运算符重载
	bool Date::operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
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
	// ==运算符重载
	bool Date::operator==(const Date& d)
	{
		return _year == d._year
		&& _month == d._month
			&& _day == d._day;

	}
	// >=运算符重载
	bool Date::operator >= (const Date& d)
	{
		return!(*this < d);
    }

	// <运算符重载
	bool Date::operator < (const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month < d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day < d._day)
				{
					return true;
				}
			}
		}
		return false;
	}
	// <=运算符重载
	bool Date::operator <= (const Date& d)
	{
		return !(*this > d);
		
	}
	// !=运算符重载
	bool Date::operator != (const Date& d)
	{
		return !(*this == d);
	}
	// 日期-日期 返回天数
	int Date::operator-(const Date& d)
	{
		Date max = *this, min = d;
		int flag = 1;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int n = 0;
		while (min != max)
		{
			n++;
			++min;
		}
		return n * flag;
	}
	void Date::print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	ostream& operator <<(ostream& out, const Date& d)//由于class类中有隐藏变量this，所以不能放入类中进行定义。
	{
		out << d._year << "-" << d._month << "-" << d._day << endl;
		return out;
	}
	istream& operator >>(istream& in, Date& d)
	{
		in >> d._year >> d._month >> d._day;
		return in;
	}
