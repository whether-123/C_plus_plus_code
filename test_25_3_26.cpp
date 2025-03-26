class Solution {
    public:
        int mySqrt(int x) 
        {
            int left = 0;
            int right = x;
            long long index = 0;
            int ret = 0;
    
            // 二分查找  在[0,x] 中寻找 最接近的平方根
            while (left <= right)
             {
                index = (left + right) >> 1;
                if ((index * index) <= x) 
                {
                    ret = index;
                    left = index + 1;
                } 
                else 
                {
                    right = index - 1;
                }
            }
            return ret;
        }
    };