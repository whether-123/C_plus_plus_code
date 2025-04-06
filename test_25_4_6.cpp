class Solution {
public:
    vector<vector<int>> ret;

    void Trace(vector<int>& nums, int start) 
    {
        if (start == nums.size()-1)
        {
            ret.push_back(nums);
            return;
        }
        
        //增加一个set，来判断当前与start位置交换的元素
        //是否前面已经有相同的元素交换过
        set<int> flag;
        for (int i = start; i < nums.size(); i++) 
        {
            if (!flag.count(nums[i])) 
            {
                flag.insert(nums[i]);
                swap(nums[i], nums[start]);
                Trace(nums, start + 1);
                swap(nums[i], nums[start]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        Trace(nums, 0);
        return ret;
    }
};