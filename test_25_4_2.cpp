class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        // 用来记录，前i间房，能够偷窃到的最多的钱
        vector<int> Maxmoney1(len - 1);
        vector<int> Maxmoney2(len);
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        if (len == 2)
            return nums[1] > nums[0] ? nums[1] : nums[0];

        //拆分[1,n-1]间房 和 [2,n]间房 这样就不会因为首尾连接成环发生冲突
        //需要两次动态规划
        Maxmoney1[0] = nums[0];
        Maxmoney1[1] = nums[1] > nums[0] ? nums[1] : nums[0];
        Maxmoney2[1] = nums[1];
        Maxmoney2[2] = nums[2] > nums[1] ? nums[2] : nums[1];
        
        // 因为不能偷窃到相邻房子里面的钱
        // Maxmoney[i]从下面的最大值中选取
        // Maxmoney[i - 2] + nums[i]
        // Maxmoney[i - 1]
        for (int i = 2; i < len - 1; i++) 
        {
            Maxmoney1[i] = max(Maxmoney1[i - 2] + nums[i], Maxmoney1[i - 1]);
        }

        for (int i = 3; i < len; i++) 
        {
            Maxmoney2[i] = max(Maxmoney2[i - 2] + nums[i], Maxmoney2[i - 1]);
        }

        return max(Maxmoney1[len - 2],Maxmoney2[len - 1]);
    }
};