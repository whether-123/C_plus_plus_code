class Solution {
public:
    bool _isSymmetric(TreeNode* Lroot, TreeNode* Rroot) 
    {
        if (Lroot == nullptr && Rroot == nullptr)
            return true;
        if (Lroot == nullptr || Rroot == nullptr)
            return false;
        //递归比较左右子树
        if (Lroot->val == Rroot->val)
        {
            bool flag1 = _isSymmetric(Lroot->left, Rroot->right);
            bool flag2 = _isSymmetric(Lroot->right, Rroot->left);

            return flag1 && flag2;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) 
    {
        if (root == nullptr)
            return false;
        //分别传入左子树和右子树   
        return _isSymmetric(root->left, root->right);
    }
};