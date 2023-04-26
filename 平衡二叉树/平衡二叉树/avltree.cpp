#include"avltree.h"
template<class k, class v>
 bool avltree<k, v>::insert(const pair<k, v>& kv)
{
	if (_root == nullptr)
	{
		_root = new node(kv);
		return true;
	}
	else
	{
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
	}
	cur = new node(kv);
	if (parent->_kv.first < kv.first)
	{
		parent->_right = cur;
	}
	else if (parent->_kv.first > kv.first)
	{
		parent->_left = cur;
	}
	cur->_parent = parent;
	//����ƽ������
	/*���¹���
	* 1.�������ң�parent->bf++������parent->bf--
	* 2.���º�parent->bf=1����-1��˵������ǰparent����������ȣ���������ˣ���Ҫ���ϸ���
	* 3.������º�Ϊ0��˵������ǰΪ1or-1�����������һ���ߣ�parent�����߶Ȳ��䣬����Ҫ�������¡�
	* 3.���º�parent->bf==2or-2��˵������ǰ�Ѿ���1or-1����������ƽ�⣬parent������Ҫ��ת����
	*/
	while (parent)
	{
		if (cur == parent->_right)
		{
			parent->_bf++;
		}
		else
		{
			parent->_bf--;
		}
		if (parent->_bf == 0)
		{
			break;
		}
		if (abs(parent->_bf) == 1)
		{
			parent = parent->_parent;
			cur = cur->_parent;
		}
		else if (abs(parent->_bf) == 2)
		{

		}
		else
		{
			assert(false);
		}
	}
	return true;
}
template<class k, class v>
void avltree<k, v>::rotatel(node* parent)//����
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
template<class k, class v>
void avltree<k, v>::rotater(node* parent)
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
	if (_root == subl)
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
template<class k, class v>
void avltree<k, v>::rotatelr(node* parent)
{
	node* subl = parent->_left;
	node* sublr = subl->_right;
	int bf = sublr->_bf;
	rotatel(parent->_left);
	rotater(parent->_left);
	sublr->_bf = 0;
	if (bf == 1)
	{
		parent->_bf = 0;
		subl->_bf = -1;
	}
	else if (bf == -1)
	{
		parent->_bf = 0;
		subl->_bf = 1;
	}
	else if (bf == 0)
	{
		parent->_bf = 0;
		subl->_bf = 0;
	}
	else
	{
		assert(false);
	}
}

