#pragma once

enum Colour
{
	BLACK,
	RED,
};

template<class T,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;
	Colour _col;

	RBTreeNode(const pair<K,V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_col(RED)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		//按搜索树的规则进行插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
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
		 
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		
		//新增结点红的 -> 不是一定会触犯规则，且就算影响也是影响一条路径
		cur->_col = RED;
		while (parent && parent->_col == RED)
		{
		   //红黑色的条件关键看叔叔
			Node* grandfther = parent->_parent;
			if (grandfther->_left == parent) //新结点的位置 在爷爷的左边
			{
				Node* uncle = grandfther->_right;
				//情况1：uncle存在，且为红
				if (uncle && uncle->_col == RED)
				{
					//红叔：染色+变新 -> 叔父爷染色，爷变为新结点
					parent->_col = uncle->_col = BLACK;
					grandfther->_col = RED;

					//需要继续往上处理
					cur = grandfther;
					parent = cur->_parent;
				}
				else
				{   //情况3：黑叔  双旋LR -> 变为单旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}

					//情况2：黑叔  单旋LL (ps：有可能是第三种情况变过来的)
					RotateR(grandfther);
					grandfther->_col = RED;
					parent->_col = BLACK;
					//处理完就结束了 不需要向上处理
					break;
				}

			}
			else  //新节点的位置 在爷爷的右边
			{
				Node* uncle = grandfther->_left;
				//情况1：uncle存在，且为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfther->_col = RED;

					//继续往上更新
					cur = grandfther;
					parent = cur->_parent;
				}
				else
				{
					//情况3：双旋  黑叔 -> 转变成单旋(情况2)
					if (cur == parent->_left)
					{
						RotateR(parent);
						//交换的是结点的指针，不影响树的结点本身的链接关系
						swap(parent, cur);//交换后儿换爷 变成 单旋父换爷
					}
					//情况2：单旋 黑叔
					RotateL(grandfther);
					grandfther->_col = RED;
					parent->_col = BLACK;
				}
			}
		}
		_root->_col = BLACK;

		return true;
	}

	//三叉链 虽然好找父亲，但是旋转时会增加难度
	void RotateL(Node* parent) //左单旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;

		//1.原来parent是这棵树的根，现在subR是根
		//2.parent为根的树只是整棵树中的子树，改变链接关系，那么subR要顶替他的位置
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;

			subR->_parent = ppNode;
		}
	}

	void RotateR(Node* parent) //右单旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;

			subL->_parent = ppNode;
		}
	}

private:
	Node* _root = nullptr;

};

