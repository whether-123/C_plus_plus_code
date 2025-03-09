// 先满足最底层  再满足最左边
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* temp = nullptr;
        int ret = 0;

        q.push(root);
        //模拟层序遍历 (从右往左)
        //最后一个出队的节点 一定是最底层 最左边的节点
        while (!q.empty()) 
        {
            temp = q.front();
            q.pop();

            if (temp->right != nullptr)
            {
                q.push(temp->right);
            }

            if (temp->left != nullptr) 
            {
                q.push(temp->left);
            }

            ret = temp->val;
        }
        return ret;
    }
};