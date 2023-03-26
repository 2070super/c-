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
	bool erase(k value)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < value)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > value)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
		//查找完成
			if (cur->_left == nullptr)//左子树为空
			{
				if (cur == _root)//只有右子树
				{
					_root = cur->_right;
				}
				else
				{
					if (cur == parent->_left)//在左边
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
				}
				delete cur;
			}
			else if (cur->_right == nullptr)
			{
				if (_root == cur)
				{
					_root = cur->_left;
				}
				else 
				{
					if (cur == parent->_left)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
				}
				delete cur;
			}
			else
			{
				Node* minparent = cur;
				Node* min = cur->_right;
				while (min->_left)
				{
					minparent = min; 
					min = min->_left;
				}
				std::swap(cur->_key, min->_key);
				if (minparent->_left == min)
				{
					minparent->_left = min->_right;
				}
				else
				{
					minparent->_right = min->_right;
				}
				delete min;
			}
			return true;
		 }

		}
		return false;
	}
	bool find(const k& key)
	{
		return _find(_root, key);
	}
private:
	Node* _root;
	bool _find(Node* root, const k& key)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->_key < key)
		{
			return _find(root->_right)
		}
	}
};