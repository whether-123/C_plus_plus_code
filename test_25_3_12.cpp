class Solution {
public:
    void _increasingBST(TreeNode* root, TreeNode*& prev) {
        if (!root)
        {
            return;
        }
           
        _increasingBST(root->left, prev);
        //根据中序遍历  用prev记录上一个节点 
        if (!prev)
        {
            prev = root;
        }  
        else 
        {
            prev->right = root;
            prev->left = nullptr;
            prev = root;
        }

        _increasingBST(root->right, prev);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if (!root)
        {
            return nullptr;
        }
           
        TreeNode* new_root = root;
        //找到最左节点 作为新的根节点
        while (new_root->left)
        {
            new_root = new_root->left;
        }
            
        TreeNode* prev = nullptr;
        _increasingBST(root, prev);
     
        //走到最后一个节点  右子树一定为空
        //仅需将 左子树置为空即可
        if(prev!=nullptr)
        {
            prev->left = nullptr;
        }
        return new_root;
    }
};