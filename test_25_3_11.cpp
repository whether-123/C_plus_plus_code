class Solution {
public:
    void depth_first(TreeNode* root, long long sum, int target, int& count,
                     unordered_map<long long, long long>& record) {
        if (root == nullptr)
            return;

        sum += root->val;
        // 如果 记录中存在 sum-target
        // 说明从本节点往上走一定存在一条路径和为target
        if (record.find(sum - target) != record.end())
            count += record[sum - target];
        // 往下走时 记录上层节点的sum
        record[sum]++;

        depth_first(root->left, sum, target, count, record);
        depth_first(root->right, sum, target, count, record);
        // 往上走时(回退时) 删除掉下层节点的sum
        record[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        unordered_map<long long, long long> record;

        // 初始化 当存在路径从根节点开始的情况
        record[0] = 1;
        // 前序遍历的思想  自顶向下 寻找合适的路径
        depth_first(root, 0, targetSum, count, record);

        return count;
    }
};