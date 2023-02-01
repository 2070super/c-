#pragma once
#include<assert.h>
#include <utility>
namespace bit
{
	template<class T>
	class vector
	{
		
	public:
		typedef T* iterator;
		vector();
		~vector();
		vector(size_t a, const T& x);
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
		void pop_back();
		void insert(iterator& pos, const T& x);//insert增容就会导致it失效。
		//解决办法：返回新插入数据位置的迭代器：return pos;
		void erase(iterator pos);//erase完后it也会失效，it如果是最后一个数据，那么删除后it就失效了。
		void resize(size_t n,const T& val=T());//T()调用空的构造函数来作为缺省值
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}