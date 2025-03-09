class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* temp = nullptr;
        vector<int> v;
         
        if(root==nullptr) return v;
        int ret = 0;
        int level = 1;
        q.push(root);

        //层序遍历  内层循环控制 每次出完同一层 
        //这样每层最后一个出的 必然是最右节点
        while (!q.empty()) {
            int i = level;
            level = 0;
            for (; i > 0; i--) 
            {
                temp = q.front();
                q.pop();

                if (temp->left != nullptr) 
                {
                    q.push(temp->left);
                    level++;
                }

                if (temp->right != nullptr) 
                {
                    q.push(temp->right);
                    level++;
                }
                ret = temp->val;
            }
            v.push_back(ret);
        }
        return v;
    }
};