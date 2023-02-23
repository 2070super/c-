#pragma once
#include "common.h"
template<class T>
class objectpool
{
public:
	T* New()
	{
		T* obj;
		if (_freelist)
		{
			obj = (T*)_freelist;
			_freelist = (void*)*((int*)_freelist); 
		}
		else
		{
			if (_endsize<sizeof(T))
			{
				_memory = (char*)malloc(1024 * 10);
				_endsize = 1024 * 10;
				if (_memory == nullptr)
				{
					throw std::bad_alloc();
				}
			}
			 obj = (T*)_memory;
			_memory += sizeof(T);
			_endsize -= sizeof(T);
			new(obj)T;//显式调用T的构造函数初始化OBJ
			return obj;
		}
			
	}
	void Delete(T* obj)
	{
		obj->~T();
		*((int*)obj) = (int)_freelist;//头插法
		_freelist = obj;
	}
private:
	char* _memory=nullptr;
	int _endsize = 0;
	void* _freelist=nullptr;//还回来的
};