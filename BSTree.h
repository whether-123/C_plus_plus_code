#pragma once

template<class X>
struct BSTreeNode // Binary Search Tree Node
{
	BSTreeNode<X>* _left;
	BSTreeNode<X>* _right;
	X _key;

	BSTreeNode(const X& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};

template<class X>
class BSTree // Binary Search Tree
{
	typedef BSTreeNode<X> Node;
public:
	bool Insert(const X& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
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
				return false; //表示已经有这个结点了
			}
		}
		 
		cur = new Node(key); //找到对应的位置后 存入结点
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

	bool Find(const X& key) //能用循环尽量别用递归
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool Erase(const X& key)  //删除
	{
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
			else   //找到了，开始删除
			{
				if (cur->_left == nullptr)	 //左为空
				{
					if (cur == _root)    //删除的结点为根且左子树为空时
					{ 
						_root = cur->_right;
					}
					else
					{
                        if (parent->_left == cur)
						  parent->_left = cur->_right;
					    else
						  parent->_right = cur->_right;
					}

					delete cur;
					cur = nullptr;
					
				}
				else if (cur->_right == nullptr) //右为空
				{
					if (cur == _root)   //删除的结点为根且右子树为空时
					{
						_root = cur->_left;
					}
					else
					{
                       if (parent->_left == cur)
						parent->_left = cur->_left;
					   else
						parent->_right = cur->_left;
					}
					delete cur;
					cur = nullptr;
				}
				else    //左右均不为空 -> 找左子树的最大(右)结点 或 找右子树的最小(左)结点 来代替
				{
					Node* RightMin = cur->_right;
					Node* RightMinparent = nullptr;
	
					while (RightMin->_left)
					{
						RightMinparent = RightMin;
						RightMin = RightMin->_left;
					}
					   
					cur->_key = RightMin->_key;//代替要删除的结点
					if (RightMinparent == nullptr) //当右孩子没有左子树时
					{
                       cur->_right = RightMin->_right;
					}
					else  //右孩子有左子树时
					{ 
					   RightMinparent->_left = RightMin->_right; //RightMin的左结点一定为空，不管右结点为不为空 都直接让parent续上
                    }
					delete RightMin;
					cur = nullptr;    // 三种情况 执行完后均要将cur置为空
				}
			}
		}

		return false;
	}

	void _InOrder(Node* root) //中序遍历
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);      //左
		cout << root->_key << " ";  //根
		_InOrder(root->_right);     //右
	}

	void InOrder() //因为在类外面拿不了root 所以写一个子函数
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	Node* _root = nullptr;
};