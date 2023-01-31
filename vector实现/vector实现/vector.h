#pragma once
#include<assert.h>
namespace bit
{
	template<class T>
	class vector
	{
		
	public:
		typedef T* iterator;
		vector();
		~vector();
		void push_back(const T& x);
		void check_vector();
		size_t capacity();
		size_t size();
		void reserve(size_t s);
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		T& operator[](size_t pos);
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}