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
	//更新平衡因子
	/*更新规则：
	* 1.新增在右，parent->bf++，在左，parent->bf--
	* 2.更新后，parent->bf=1或者-1，说明插入前parent左右子树相等，插入后变高了，需要往上更新
	* 3.如果更新后为0，说明插入前为1or-1，插入后两边一样高，parent子树高度不变，不需要继续更新。
	* 3.更新后parent->bf==2or-2，说明更新前已经是1or-1，插入后打破平衡，parent子树需要旋转处理。
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
void avltree<k, v>::rotatel(node* parent)//左旋
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

