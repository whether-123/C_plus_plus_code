class Solution {
public:
    TreeNode* flipTree(TreeNode* root) {
        if(root==nullptr)
        return nullptr;
        
        //交换左右节点(都为空也可以)
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;

        flipTree(root->left);
        flipTree(root->right);
        
        return root;
    }
};