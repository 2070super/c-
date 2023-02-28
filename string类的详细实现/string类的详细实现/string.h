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
		typedef char* iterator;
		iterator begin();//暂时不知道如何将该方法写入cpp
		iterator end();
		iterator begin() const;
		iterator end() const;
		string(const char* str="");
		size_t size();
		size_t size() const;
		char& operator[](size_t t);
		char& operator[](size_t t) const;
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
		size_t find(size_t pos, char ch);
		size_t find(const char*sub,size_t pos);
		
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		static const size_t npos=-1;
	};
}
bool operator==(const string & s1, const string & s2);
bool operator>(const string& s1, const string& s2);
bool operator <(const haha::string& s1, const haha::string& s2);
ostream& operator<< (ostream& out, const haha::string& s);
istream& operator>>(istream& in, const haha::string& s);