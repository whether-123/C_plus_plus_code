class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> _hash; // k记录前缀和 v记录对应的数组下标
        int len=nums.size();
        int maxl=0,sum=0;
        _hash[0]=-1;  //前缀和为0  第一次出现是 下标 "-1" (-1仅用来计算区间长度)
        
        //记录前缀和时 将0转换成 -1 -> 转换成了和为0的最长连续子数组
        for(int i=0;i<len;i++) 
        {
            if(nums[i]==0)  sum--;
            else            sum++;

            //有相同大小的前缀和时 只记录第一次出现时的下标
            //因为是从左到右遍历的 这样保证了记录的下标是最小的
            //从而相减保证了区间长度最大
            if(_hash.count(sum))    maxl = max(maxl,i-_hash[sum]);
            else                    _hash[sum]=i; 
        }

        return maxl;
    }
};