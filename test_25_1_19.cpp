class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len=nums.size();
        vector<vector<int>>  temp;

        sort(nums.begin(),nums.end()); // 排序 便于查找时 固定次序 a<=b<=c

        for(int first=0;first<len;++first) //先固定a
        {
            if(first>0 && nums[first]==nums[first-1]) continue; // 与上一次a相同则 跳出(避免重复)
            
            int target=-nums[first];   //转换成求两数之和 

            int second = first+1, third = len-1;  
        while (second < third)   //双指针 
        {   
            if(second>first+1&& nums[second]==nums[second-1]) // 与上一次b相同则 跳出(避免重复)  
            {
                ++second;
                continue;
            }
            if (nums[second] + nums[third] == target) {   //满足要求 尾插
                temp.push_back({nums[first],nums[second],nums[third]});
                ++second;
                --third;
            } else if (nums[second] + nums[third] < target) {
                 ++second;
            } else {
                --third;
            }
        }
        }
        return  temp;
    }
};