#pragma once
#include<iostream>
#include <cassert>
#include<algorithm>
namespace haha
{
	class string
	{
	public:
		~string();
		string();
		typedef char* iterator;
		iterator begin()//暂时不知道如何将该方法写入cpp
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		iterator begin() const//暂时不知道如何将该方法写入cpp
		{
			return _str;
		}
		iterator end() const
		{
			return _str + _size;
		}
		string(const char* str);
		size_t size();
		char& operator[](size_t t);
		void push_back(char ch);
		void append(const char* ch);
		void reserve(size_t t);
		string& operator+=(char ch);
		string& operator+=(const string& ch);
		string& operator+=(const char* ch);
		string(const string& s);
		string& operator=(const string& s);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}
