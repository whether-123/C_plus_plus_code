class Solution
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        if (k < 1 || root == nullptr) 
        {
            return -1;
        }

        return _kthSamllest(root, k)->val;
    }

    TreeNode* _kthSamllest(TreeNode* root, int& k) 
    {
        // 中序遍历
        TreeNode* target = nullptr;
        if (root->left != nullptr) 
        {
            target = _kthSamllest(root->left, k);
        }

        // 1.不在左子树中，且不是本节点，--k
        // 2.在左子树中找到了，则不做处理，返回taget即可
        if (target == nullptr) 
        {
            if (k == 1) 
            {
                target = root;
            }

            --k;
        }

        // 左子树和都没找到时，去右子树中找
        if (target == nullptr && root->right != nullptr) 
        {
            target = _kthSamllest(root->right, k);
        }

        return target;
    }
};