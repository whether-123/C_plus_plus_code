class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
     unordered_map<int,int> count; 
     for(auto number : nums)
     {
         count[number]++;  //KV模型
     }

     int N=nums.size()/2;
     for(auto kv : count)
     {
         if(kv.second==N)
         {
             return kv.first;
         }
     }
       return -1;
    }
};