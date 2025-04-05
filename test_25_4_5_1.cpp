class Solution {
public:
    vector<vector<int>> ret;

    void Trace(vector<int>& nums, int start)
    {     
        if (start == nums.size() - 1) 
        {
            ret.push_back(nums);
            return;
        }
        
        //每次进来前，[0,start-1] 下标的元素，位置已经确定
        //start位置元素的可能 -- [start,size-1],循环模拟出每种可能
        //每种位置可能的清况，在枚举完后，回溯时会交换回来
        //避免影响当前位置下一种可能的情况
        for (int i = start; i < nums.size(); i++) 
        {
            swap(nums[i], nums[start]);

            Trace(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        Trace(nums, 0);
        return ret;
    }
};