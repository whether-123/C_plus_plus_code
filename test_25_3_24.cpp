class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int index = 0;

        while (left < right)
        {
            index = (left + right) >> 1;
            //index为偶数时只会向index+1去比
            //index为奇数时只会向index-1去比
            //数组个数为奇数 数组下标[0,偶数]
            //index为奇数时 index-1不会越界
            //index为偶数时 index=最右边界时 index+1会越界
            //但是当index=最右边界时 一定是left=right=右边界时才可能 
            //此时已经不满足条件 会结束 故数组访问都不会越界 
            if (nums[index] == nums[index ^ 1])
            {
                left = index + 1;
            } 
            else 
            {
                right = index;
            }
        }
        return nums[left];
    }
};