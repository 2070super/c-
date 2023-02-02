#pragma once
#include <iostream>
namespace bit
{
	template<class T>
	struct _list_node
	{
		T _data;
		_list_node<T>* _next;
		_list_node<T>* _prev;
		_list_node(const T& x)
			:_data(x),
			_next(nullptr),
			_prev(nullptr)
		{}
	};
	template<class T>
	class list
	{
		typedef _list_node<T> node;
	public:
		list()
		{
			_head == new node(T());
			_head->next = _head;
			_head->prev = _head;
		}

		void push_back(const T& x)
		{
			node* newcode = new node(x);
			node* tail = _head->_prev;
			tail->_next = newcode;
			newcode->_prev = tail;
			newcode->_next = _head;
			_head->_prev = newcode;
		}
		typedef _list_iterator<T,T&,T*> iterator;
		typedef _list_iterator<T, const T&,const T*> const_iterator;
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		const_iterator begin() const
		{
			return _head->_next;
		}
		const_iterator end() const
		{
			return _head;
		}
	private:
		node* _head;
	};
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T,Ref,Ptr> self;
		node* _node;
		_list_node(node* s)
			:_node(s)
		{
		}
		bool operator!=(const self& s)
		{
			return _node != self._node;
		}
		bool operator==(const self& s)
		{
			return !(*this != s);
		}
		self operator *()
		{
			return _node->_data;
		}
		self& opertator++()
		{
			_node = _node->next;
			return *this;
		}
		iterator begin()
	};
}