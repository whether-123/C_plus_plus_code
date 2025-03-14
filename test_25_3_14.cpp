class BSTIterator {
public:
    TreeNode* cur;
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) 
    { 
        cur = root; 
    }

    //非递归模拟中序遍历
    int next() 
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }

        cur = st.top();
        int temp = cur->val;
        st.pop();
        cur = cur->right;
        return temp;
    }

    bool hasNext() 
    { 
        return cur || !st.empty(); 
    }
};
