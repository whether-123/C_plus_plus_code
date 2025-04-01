class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        //用来记录，前i间房，能够偷窃到的最多的钱
        vector<int> Maxmoney(len);

        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        if (len == 2)
            return nums[1] > nums[0] ? nums[1] : nums[0];
        
        Maxmoney[0] = nums[0];
        Maxmoney[1] = nums[1] > nums[0] ? nums[1] : nums[0];
        
        //因为不能偷窃到相邻房子里面的钱
        //Maxmoney[i]从下面的最大值中选取
        //Maxmoney[i - 2] + nums[i]
        //Maxmoney[i - 1]
        for (int i = 2; i < len; i++) {
            Maxmoney[i] = max(Maxmoney[i - 2] + nums[i], Maxmoney[i - 1]);
        }

        return Maxmoney[len - 1];
    }
};