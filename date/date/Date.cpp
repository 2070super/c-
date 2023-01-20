#include"Date.h"
	// ��ȡĳ��ĳ�µ�����
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

	// ȫȱʡ�Ĺ��캯��
	Date::Date(int year, int month , int day )
	{
		if (year >= 0 && month > 0 && month < 13 && day>0 && day < GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
			cout << "���ڷǷ�" << endl;
	}
	// �������캯��
	// d2(d1)
	Date::Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& Date::operator=(const Date& d)
	{
		if(this!=&d)//���d2=d2
		{
		_year = d._year;
		_month = d._month;
		_day = d._day; 
		}
		return *this;//���d1=d2=d3
	}
	// ���������ɱ��������
	// ����+=����
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
	// ����+����
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
	// ����-����
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
	
		// ����-=����
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
	// ǰ��++
	Date& Date::operator++()
	{
		*this += 1;
		return *this;
	}
	// ����++
	Date Date::operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}
	// ����--
	Date Date::operator--(int)
	{
		*this -= 1;
		return *this;
	}
	// ǰ��--
	Date& Date::operator--()
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}

	// >���������
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
	// ==���������
	bool Date::operator==(const Date& d)
	{
		return _year == d._year
		&& _month == d._month
			&& _day == d._day;

	}
	// >=���������
	bool Date::operator >= (const Date& d)
	{
		return!(*this < d);
    }

	// <���������
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
	// <=���������
	bool Date::operator <= (const Date& d)
	{
		return !(*this > d);
		
	}
	// !=���������
	bool Date::operator != (const Date& d)
	{
		return !(*this == d);
	}
	// ����-���� ��������
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
	ostream& operator <<(ostream& out, const Date& d)//����class���������ر���this�����Բ��ܷ������н��ж��塣
	{
		out << d._year << "-" << d._month << "-" << d._day << endl;
		return out;
	}
	istream& operator >>(istream& in, Date& d)
	{
		in >> d._year >> d._month >> d._day;
		return in;
	}
