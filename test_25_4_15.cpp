class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }

        int maxSum=0x80000000;
        int tempSum=0;
        //遍历一趟
        for(int i=0;i<nums.size();i++)
        {
            //如果前面的i-1的和小于0，则舍去
            //相当于 前面累加的和，与num[i]相加 比num[i]还小
            if(tempSum<=0)
            {
                tempSum=nums[i];
            }
            //不小于0，累加到一起
            else
            {
                tempSum+=nums[i];
            }
            //当前累加的和，比之前记录的大，则记录
            if(tempSum>maxSum)
            {
                maxSum=tempSum;
            }
        }
        return maxSum;
    }
};