class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> Minhead;  // 小的优先级高
        size_t i=0;
        for(;i<k;++i)   //时间复杂度O(N*logK)
        {                      //空间复杂度O(K)
            Minhead.push(nums[i]);   //建k个数的小堆
        }
        
        for(;i<nums.size();++i)
        {
            if(Minhead.top()<nums[i])  //堆顶元素小 则替换
            {
                Minhead.pop();
                Minhead.push(nums[i]);
            }
        }
    
        return Minhead.top();
        
    }
};