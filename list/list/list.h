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
		_list_node(const T& x=T())
			:_data(x),
			_next(nullptr),
			_prev(nullptr)
		{}
	};
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> *PNode;
		typedef _list_iterator<T, Ref, Ptr> Self;
		PNode _pNode;
		_list_iterator(PNode pNode = nullptr)
			: _pNode(pNode)
		{}
		bool operator!=(const Self& l)
		{
			return _pNode != l._pNode; 
		}
		bool operator==(const Self& l) 
		{
			return _pNode != l._pNode; 
		}
		_list_iterator(const Self& l)
			: _pNode(l._pNode)
		{}
		Ref operator*() 
		{ return _pNode->_data; }
		Ptr operator->() 
		{ return &(operator*()); }
		Self& operator++()
		{
			_pNode = _pNode->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_next;
			return temp;
		}
		Self& operator--()
		{
			_pNode = _pNode->_prev;
			return *this;
		}
		Self& operator--(int)
		{
			Self temp(*this);
			_pNode = _pNode->_prev;
			return temp;
		}

	};
	template<class T>
	class list
	{
		typedef _list_node<T> node;
	public:
		typedef _list_iterator<T,T&,T*> iterator;
		typedef _list_iterator<T,const T&,const T*> const_iterator;
		list()
		{
			CreateHead();
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
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head->_prev;
		}
		template <class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		iterator insert(iterator pos, const T& val)
		{
			node pNewNode = new node(val);
			node pCur = pos._node;
			// 先将新节点插入
			pNewNode->_prev = pCur->_prev;
			pNewNode->_next = pCur;
			pNewNode->_prev->_next = pNewNode;
			pCur->_prev = pNewNode;
			return iterator(pNewNode);
		}
		// 删除pos位置的节点，返回该节点的下一个位置
		iterator erase(iterator pos)
		{
			// 找到待删除的节点
			node pDel = pos._pNode;
			node pRet = pDel->_next;

			pDel->_prev->_next = pDel->_next;
			pDel->_next->_prev = pDel->_prev;
			delete pDel;
			return iterator(pRet);
		}
		list(const list<T>& lt)
		{
			CreateHead();
			iterator it = lt.begin();
			while (it != lt.begin())
			{
				push_back(*it);
				it++;
			}
		}

		private:
			node* _head;
			void CreateHead()
			{
				_head = new node;
				_head->_prev = _head;
				_head->_next = _head;
			}

	};
	

}