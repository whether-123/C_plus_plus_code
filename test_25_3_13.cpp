class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        // ret 记录可能的中序后继
        TreeNode* ret = nullptr;
        TreeNode* cur = root;

        while (cur != nullptr) 
        {
            // 当前节点值 比p大
            // 那么p一定在当前节点的左子树
            if (cur->val > p->val) {
                // 当前节点 为可能的中序后继 记录下来
                ret = cur;
                cur = cur->left;
            }
            // 否则p一定在当前节点的右子树
            else 
            {
                cur = cur->right;
            }
        }

        return ret;
    }
};