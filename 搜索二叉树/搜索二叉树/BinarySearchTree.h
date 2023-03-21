#pragma once
#include<iostream>
template<class k>
struct BSTreeNode
{

	BSTreeNode<k>* _left;
	BSTreeNode<k>* _right;
	k _key;
	BSTreeNode(const k& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};
template<class k>
struct BsTree
{
	typedef BSTreeNode<k> Node;
public:
	BsTree()
		:_root(nullptr)
	{

	}
	bool insert(const k& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		else
		{
			_InOrder(root->_left);
			std::cout << root->_key << ' ';
			_InOrder(root->_right);
		}
	}
private:
	Node* _root;
};