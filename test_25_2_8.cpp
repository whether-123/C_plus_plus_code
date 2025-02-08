class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> _hash; //利用哈希表 k记录前缀和([0,i-1]中) v记录出现的次数
        int len=nums.size();
        int count=0,sum=0;
        _hash[0]=1;  //防止出现一开始就出现前缀和为k

        for(int i=0;i<len;i++) //每次固定i 往前寻找([0,i-1]) 是否有前缀和 = sum-k 
        {
            sum+=nums[i];
            if(_hash.find(sum-k) != _hash.end()) 
            {
                count+=_hash[sum-k]; //存在则 加上前缀和 = sum-k的个数
            }
            _hash[sum]++; //将本次sum 作为下次的 前缀和判断 边计算边存入hash
        }

        return count;
    }
};