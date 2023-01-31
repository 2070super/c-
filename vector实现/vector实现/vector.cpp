#include "vector.h"
#pragma warning(disable:4996)
template<class T>
 bit::vector<T>::vector()
	:_start(nullptr),
	 _finish(nullptr),
	_endofstorage(nullptr)
{
	
}
template<class T>
bit::vector<T>::~vector()
{
	delete[] _start;
	_start = _finish = _endofstorage = nullptr;
}
template<class T>
void bit::vector<T>::push_back(const T& x)
{
	check_vector();
	*_finish = x;
	_finish++;
	
}

template<class T>
void bit::vector<T>::check_vector()
{
	if (_finish == _endofstorage)
	{
		size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
		reserve(newcapacity);
		//不能用malloc这些，因为模板可能会有自定义类
	}
}

template<class T>
size_t bit::vector<T>::capacity()
{
	return _endofstorage-_finish;
}

template<class T>
size_t bit::vector<T>::size()
{
	return _finish - _start;
}

template<class T>
void bit::vector<T>::reserve(size_t s)
{
	if (s > capacity())
	{
		size_t newsize = size();
		size_t newcapacity = s;
		T* tmp = new T[s];
		memcpy(tmp, _start, sizeof(T) * size());

		delete[] _start;
		_start = tmp;
		_finish = _start + newsize;
		_endofstorage = _start + newcapacity;

	}
}

template<class T>
T &bit::vector<T>::operator[](size_t pos)
{
	assert(pos < size());
	return _start[pos];
}

