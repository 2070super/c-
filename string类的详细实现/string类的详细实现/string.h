#pragma once
#include<iostream>
#include <cassert>
#include<algorithm>
using namespace std;
namespace haha
{
	class string
	{
	public:
		~string();
		string();
		typedef char* iterator;
		iterator begin()//��ʱ��֪����ν��÷���д��cpp
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		iterator begin() const//��ʱ��֪����ν��÷���д��cpp
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
		void swap( string& s);
		void print();
		void resize(size_t n, char ch );
		void insert(size_t n, const char* str);
		void insert(size_t n, char ch);
		char* c_str(const string& s);
		void erase(size_t pos, size_t len);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		static const size_t npos;
	};
}
const size_t npos = -1;