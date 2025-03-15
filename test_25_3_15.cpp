class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> s;
        int len = nums.size();
        for (int i = 0; i < len; i++) 
        {
            // x-t≤ y ≤x+t
            // 设置上下限 (防止越界)
            int low_limit = max(nums[i], INT_MIN + t) - t;
            int high_limit = min(nums[i], INT_MAX - t) + t;
            auto it = s.lower_bound(low_limit);
            // 如果x 左边的k个数 满足条件
            if (it != s.end() && *it <= high_limit) {
                return true;
            }
            s.insert(nums[i]);

            // 维护一个大小为k的滑动窗口
            if (i >= k) 
            {
                // num[i] 比较完后 滑动窗口向右移动一位
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};