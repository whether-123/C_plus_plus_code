class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> ret(2, -1);

        if (nums.size() == 0) {
            return ret;
        }

        // 找到第一次出现的target
        ret[0] = Getfirst_target(nums, 0, nums.size() - 1, target);
        // 找到最后一次出现的target
        ret[1] = Getlast_target(nums, 0, nums.size() - 1, target);

        return ret;
    }

    int Getfirst_target(vector<int>& nums, int start, int end, int& target) 
    {
        if (start > end)
            return -1;

        int middle = (start + end) / 2;
        // 利用二分查找
        if (nums[middle] == target) 
        {
            // 找到后，看是不是第一个target
            if ((middle > 0 && nums[middle - 1] != target) || middle == 0) 
            {
                return middle;
            }
            // 如果不是第一个target，继续在左区间中找
            end = middle - 1;
        } 
        else if (nums[middle] > target) 
        {
            end = middle - 1;
        } 
        else 
        {
            start = middle + 1;
        }

        return Getfirst_target(nums, start, end, target);
    }

    int Getlast_target(vector<int>& nums, int start, int end, int& target) 
    {
        if (start > end)
            return -1;

        int middle = (start + end) / 2;
        // 利用二分查找
        if (nums[middle] == target) 
        {
            // 找到后，看是不是最后一个target
            if ((middle < nums.size() - 1 && nums[middle + 1] != target) ||
                middle == (nums.size() - 1)) 
            {
                return middle;
            }
            // 如果不是最后一个target，继续在右区间中找
            start = middle + 1;
        } 
        else if (nums[middle] > target) 
        {
            end = middle - 1;
        } 
        else 
        {
            start = middle + 1;
        }

        return Getlast_target(nums, start, end, target);
    }
};