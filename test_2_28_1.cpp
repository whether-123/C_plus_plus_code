class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> count;  //统计次数 KV模型
        for(auto number : nums)
        {
            count[number]++;
        }

        for(auto number : count)
        {
            if(number.second>1)  //存在次数大于1 则返回true
              return true;
        }
        return false;
    }
};