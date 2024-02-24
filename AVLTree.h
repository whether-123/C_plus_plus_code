#pragma once

template<class K,class V>
struct AVTreeNode
{
	AVTreeNode<K, V>* _left;
	AVTreeNode<K, V>* _right;
	AVTreeNode<K, V>* _parent;

	int _bf;  //balance factor  平衡因子

	pair<K,V> _kv;

	AVTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(0)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef AVTreeNode<K, V> Node;

public:
	bool Insert(const pair<K,V>& kv)
	{
		//1.先按搜索树的规则进行插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
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

		//2.更新平衡因子
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
				//说明parent所在的子树的高度不变，更新结束
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//说明parent所在的子树的高度变了，继续往上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//parent所在的子树出现不平衡了，需要旋转处理。
				//1.旋转前提是保持他依旧是搜索二叉树
				//2.旋转成平衡树
				//3.这棵树的高度又恢复到插入之前
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if (cur->_bf == -1)
					{
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);
					}
				}
				
				//旋转完成后，parent所在的树的高度恢复到了，插入结点前的高度
				//如果是子树，对上层没有影响，更新结束
			  
				break;
			}
		}

		return true;
	}

	//三叉链 虽然好找父亲，但是旋转时会增加难度
	void RotateL(Node* parent) //左单旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent=parent;
		
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
	                //旋转完后 只有parent和subR 的平衡因子有变化(因为只有他们两个动了自己的孩子)
		parent->_bf = subR->_bf = 0;
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
			subL->_parent =nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;

			subL->_parent = ppNode;
		}
		
		parent->_bf = subL->_bf = 0;
	}

	void RotateRL(Node* parent)//右左双旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		//对应图来理解这里的平衡因子调节
		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if(bf==1)
		{
			parent->_bf =-1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == 0)   // subRL就是新增结点时
		{
			subR->_bf = 0;
			parent->_bf = 0;
			subRL->_bf = 0;
		}
	}

	void RotateLR(Node* parent) //左右双旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(subL);
		RotateR(parent);

		if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if(bf==-1)
		{
			parent->_bf = 1;
			subL->_bf =0;
			subLR->_bf = 0;
		}
		else if (bf == 0)  //subLR 就是新增结点时
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
	}
	
private:
	Node* _root=nullptr;
};


