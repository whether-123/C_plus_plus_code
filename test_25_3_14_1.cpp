class Solution {
public:
    unordered_set<int> _hash;

    bool findTarget(TreeNode* root, int k) 
    {
        if (root == nullptr)
            return false;

        // 如果后面 存在没有插入的节点值 满足要求
        // 不会漏掉 因为后面 插入该节点时 会在找一次
        if (_hash.count(k - root->val)) 
        {
            return true;
        }

        _hash.insert(root->val);

        bool Lfalg = findTarget(root->left, k);
        bool Rflag = findTarget(root->right, k);
        // 只要有一个存在就返回 true
        return Lfalg || Rflag;
    }
};