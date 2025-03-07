class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        _root = root;
        queue<TreeNode*> q;
        q.push(root);

        //模拟层序遍历 将可插入孩子节点的 节点存储进_insertNode
        while (!q.empty()) 
        {
            TreeNode* temp = q.front();
            q.pop();

            if (temp->left != nullptr) 
            {
                q.push(temp->left);
            }

            if (temp->right != nullptr)
            {
                q.push(temp->right);
            }

            if (temp->left == nullptr) 
            {
                _insertNode.push(temp);
            }
            else if (temp->right == nullptr) 
            {
                _insertNode.push(temp);
            }
        }
    }

    int insert(int v) {

        TreeNode* newNode = new TreeNode(v);
        TreeNode* temp = _insertNode.front();
        
        //左孩子不为空，则插入右边 并且出队
        if (temp->left != nullptr) 
        {
            temp->right = newNode;
            _insertNode.pop();
        } 
        else
        {
            temp->left = newNode;
        }
        //将新节点入队
        _insertNode.push(newNode);
        return temp->val;
    }

    TreeNode* get_root() { return _root; }

    queue<TreeNode*> _insertNode; //存储可插入孩子节点的 节点
    TreeNode* _root; //存储完全二叉树的根节点
};
