class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int index = 0;
        // 二分查找
        while (left <= right) 
        {
            index = (left + right) >> 1;
            if (nums[index] == target) 
            {
                return index;
            }
            
            if (nums[index] > target)
            {
                right = index - 1;
            }
            else 
            {
                left = index + 1;
            }
        }
        return left;
    }
};