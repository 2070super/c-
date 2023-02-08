#pragma once
#include<iostream>
#include<vector>
using namespace std;
template<class T,class Container=vector<T>>
class Priority_queue
{
public:
	void adjustup(int child)
	{
		int parent = (child - 1) / 2;
		while (child>0)
		{
			if (_con[child] > _con[parent])
			{
				swap(_con[child], _con[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
	void push(const T& x)
	{
		_con.push_back(x);
		adjustup(_con.size()-1);
		
	}
	void pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
	}
	const T& top()
	{
		return _con[0];
	}
	Container _con;
};