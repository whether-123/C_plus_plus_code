class Solution {
public:
    void right_root_left(TreeNode* root, int& sum) 
    {
        if (root == nullptr)
        {
            return;
        }
        
        right_root_left(root->right, sum);
        //sum存储 >= 当前节点 的所有值的和
        sum += root->val;
        //sum更新后  修改当前节点的值
        root->val = sum;
        right_root_left(root->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) 
    {
        int sum = 0;
        // 右 根 左
        //根据二叉搜索树的性质 从最大的节点开始遍历
        right_root_left(root, sum);
        return root;
    }
};