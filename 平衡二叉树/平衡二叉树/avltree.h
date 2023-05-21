#pragma once
#include<iostream>
#include<assert.h>
#include"avltree.h"
#include<algorithm>
template<class k ,class v>
struct avltreenode
{
	avltreenode<k, v>* _left;
	avltreenode<k, v>* _right;
	avltreenode<k, v>* _parent;
	std::pair<k, v>_kv;
	int _bf;
	avltreenode(const std::pair<k,v>& kv)
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
	bool insert(const std::pair<k, v>& kv)
	{
		if (_root == nullptr)
		{
			_root = new node(kv);
			_root->_bf = 0;
			return true;
		}
		node* parent = nullptr;
		node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		//更新平衡因子
		/*更新规则：
		* 1.新增在右，parent->bf++，在左，parent->bf--
		* 2.更新后，parent->bf=1或者-1，说明插入前parent左右子树相等，插入后变高了，需要往上更新
		* 3.如果更新后为0，说明插入前为1or-1，插入后两边一样高，parent子树高度不变，不需要继续更新。
		* 3.更新后parent->bf==2or-2，说明更新前已经是1or-1，插入后打破平衡，parent子树需要旋转处理。
		*/
		while (parent) // 最远要更新根
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			// 是否继续更新？
			if (parent->_bf == 0)  // 1 or -1  -》 0  插入节点填上矮的那边
			{
				// 高度不变，更新结束
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
				// 0  -》 1 或 -1  插入节点导致一边变高了
			{
				// 子树的高度变了，继续更新祖先
				cur = cur->_parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
				// -1 or 1  -》 2 或 -2  插入节点导致本来高一边又变高了
			{
				// 子树不平衡 -- 需要旋转处理
				if (parent->_bf == 2 && cur->_bf == 1) // 左单旋
				{
					rotatel(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1) // 右单旋
				{
					rotater(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1) // 左右双旋
				{
					rotatelr(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1) // 右左双旋
				{
					rotaterl(parent);
				}

				break;
			}
			else
			{
				// 插入之前AVL就存在不平衡子树，|平衡因子| >= 2的节点
				assert(false);
			}
		}
		return true;
	}
	void rotatel(node* parent)
	{
		node* subr = parent->_right;
		node* subrl = subr->_left;
		parent->_right = subrl;
		if (subrl)
		{
			subrl->_parent = parent;
		}
		node* ppnode = parent->_parent;
		subr->_left = parent;
		parent->_parent = subr;
		if (_root == parent)
		{
			_root = subr;
			subr->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subr;
			}
			else
			{
				ppnode->_right = subr;
			}
			subr->_parent = ppnode;
		}
		subr->_bf = parent->_bf = 0;
	}
	void rotater(node* parent)
	{
		node* subl = parent->_left;
		node* sublr = subl->_right;
		parent->_left = sublr;
		if (sublr)
		{
			sublr->_parent = parent;
		}
		node* ppnode = parent->_parent;
		subl->_right = parent;
		parent->_parent = subl;
		if (parent==_root)
		{
			_root = subl;
			subl->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subl;
			}
			else
			{
				ppnode->_right = subl;
			}
			subl->_parent = ppnode;
		}
		subl->_bf = parent->_bf = 0;
	}
	void rotatelr(node* parent)
	{
		node* subl = parent->_left;
		node* sublr = subl->_right;
		int bf = sublr->_bf;
		rotatel(parent->_left);
		rotater(parent);
		sublr->_bf = 0;
		if (bf == 0)
		{
			parent->_bf = 0;
			subl->_bf = 0;
			sublr->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			subl->_bf = -1;
			sublr->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subl->_bf = 0;
			sublr->_bf = 0;
		}
		else
		{
			// subLR->_bf旋转前就有问题
			assert(false);
		}
	}
	void rotaterl(node* parent)
	{
		node* subr = parent->_right;
		node* subrl = subr->_left;
		int bf = subrl->_bf;
		rotater(parent->_right);
		rotatel(parent);
		if (bf == 0)
		{
			subr->_bf = 0;
			parent->_bf = 0;
			subrl->_bf = 0;
		}
		else if (bf == 1)
		{
			subr->_bf = 0;
			parent->_bf = -1;
			subrl->_bf = 0;
		}
		else if (bf == -1)
		{
			subr->_bf = 0;
			parent->_bf = 0;
			subrl->_bf = 1;
		}
		else
		{
			assert(false);
		}
	}
	void inorder()
	{
		_inorder(_root);
		std::cout << std::endl;
	}
	bool isbalance()
	{
		return _isbalance(_root);
	}
private:
	bool _isbalance(node* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		int leftht = hight(root->_left);
		int righth = hight(root->_right);
		int diff = righth - leftht;
		if (diff != root->_bf)
		{
			std::cout << root->_kv.first << "平衡因子异常" << std::endl;
		}
		return (abs(righth - leftht) < 2) && _isbalance(root->_left) && _isbalance(root->_right);
	}
	int hight(node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int leftht = hight(root->_left);
		int righht = hight(root->_right);
		return std::max(leftht, righht) + 1;
	}
	node* _root=nullptr;
	void _inorder(node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_inorder(root->_left);
		std::cout << root->_kv.first << ":" << root->_kv.second << std::endl;
		_inorder(root->_right);
	}
};