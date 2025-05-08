class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return true;
        }

        bool flag = true;
        //自底向上传递左右子树高度
        _isBalanced(root,flag);

        return flag;
    }

    int _isBalanced(TreeNode* root , bool& flag)
    {
        //递归结束条件
        if(root == nullptr)
        {
            return 0;
        }

        int left = 0;
        int right = 0;
        //flag为假时，说明不是二叉搜索树，没必要在递归下去
        if(flag)
        {
            left = _isBalanced(root->left,flag);
        }

        if(flag)
        {
            right = _isBalanced(root->right,flag);
        }

        int banlance = left -right;

        //左右子树高度差，不满足条件时flag 设为假
        if(flag && (banlance < -1 || banlance >1))
        {
            flag = false;
        }

        return (left > right) ? (left+1) : (right+1);
    }
};