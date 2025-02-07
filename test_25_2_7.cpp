class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int len = nums.size();
        int count=0,multi=1;
        int front = 0, rear = 0;  //双指针

      multi *= nums[0];  
      while (front <= rear && front < len)
      {
         while (rear < len && multi < k)
         { 
             ++rear;
             if(rear<len) 
             multi *= nums[rear];
         }
          count += rear - front;  //[front,rear-1] 统计以front为首 依次往后的连续序列 
          multi /= nums[front];   // 下次从 front+1 开始统计
          if(rear==front)  rear++;  //数组中单独一个数 大于k时 rear，front都++
          front++;
    }
        return count;
    }
};