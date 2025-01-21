class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int Min=0x7fffffff;
        int front = 0, rear = 0;  //双指针

        size_t sum=nums[0]; 
        while(front<len)   //区间 头指针移动到数组尾部结束
        {
           while(rear<len && sum < target) // 满足sum<target 移动区间 尾指针
           {
             ++rear;
             if(rear<len)     //防止rear = len 数组越界
             sum+=nums[rear];
           }

           if(Min>(rear-front+1)&&sum >= target) // rear走到len时依旧小于target 不更新
           Min = rear-front+1;
           sum-=nums[front];  
           ++front; 
        } 
        if(Min==0x7fffffff) //不存在时 返回0
         Min=0;
        return Min;
    }
};