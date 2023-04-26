#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
template<class k ,class v>
struct avltreenode
{
	avltreenode<k, v>* _left;
	avltreenode<k, v>* _right;
	avltreenode<k, v>* _parent;
	pair<k, v>_kv;
	int _bf;
	avltreenode(const pair<k,v>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(0)
	{}
};
template<class k, class v>
struct avltree
{
	typedef avltreenode<k, v> node;
public:
	bool insert(const pair<k, v>& kv);
	void rotatel(node* parent);
	void rotater(node* parent);
	void rotatelr(node* parent);
preivate:
	node* _root=nullptr;
};