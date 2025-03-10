class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr) 
        {
            return nullptr;
        }

        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);

        //采用后序遍历的思想  从下往上删除 满足要求的节点
        if(root->left==nullptr&&root->right==nullptr&&root->val==0)
        {
           // delete root;
            return nullptr;
        }

        return root;

    }
};