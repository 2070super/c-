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
bit::vector<T>::vector(size_t a, const T& x)
	:_start(nullptr),
	_finish(nullptr),
	_endofstorage(nullptr)
{
	vector tmp;
	tmp.reserve(a);
	for (size_t i = 0; i < a; i++)
	{
		tmp.push_back(x);
	}
	std::swap(tmp._start, _start);
	std::swap(tmp._finish, _finish);
	std::swap(tmp._endofstorage, _endofstorage);
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
		size_t newcapacity;
		if (_endofstorage == 0)
		{
			newcapacity = 4;
		}
		else
		{ 
			newcapacity = 2 * capacity();;
		} 
		reserve(newcapacity);
		//不能用malloc这些，因为模板可能会有自定义类
	}
}

template<class T>
size_t bit::vector<T>::capacity()
{
	return _endofstorage - _start;

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
		//memcpy(tmp, _start, sizeof(T) * size());由于是浅拷贝，新的string中_Str传过去只会传值，但是在析构后_str就变成了野指针。
		for (size_t i = 0; i <newsize;++i)
		{
			tmp[i] = _start[i];
		}

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

template<class T>
void bit::vector<T>::insert(iterator& pos, const T& x)//当心迭代器失效
{
	assert(pos >= _start && pos <= _finish);
	size_t posi = pos - _start;
	check_vector();
	pos = _start + posi;
	iterator end = _finish - 1;
	while (end >= pos)
	{
		*(end + 1) = *end;
		--end;
	}
	*pos = x;
	_finish++;
}

template<class T>
void bit::vector<T>::erase(iterator pos)
{
	assert(pos < _finish&&pos>=_start);
	iterator it = pos + 1;
	while (it != _finish)
	{
		*(it - 1) = *it;
		it++;
	}
	--_finish;
}

template<class T>
void bit::vector<T>::resize(size_t n, const T& val)
{
	if (n > capacity())
	{
		reserve(n);
	}
	
	if (n < size())
	{
		_finish = _start + n;
	}
	else
	{
		while (_finish != _start + n)
		{
			*_finish = val;
			++_finish;
		}


	}
}


