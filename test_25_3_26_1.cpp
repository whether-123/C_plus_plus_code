class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        //算出最大速度 
        for (auto v : piles) 
        {
            if (v > right) 
            {
                right = v;
            }
        }

        int index = 0;
        while (left < right) 
        {
            int retTime = 0;
            index = (left + right) >> 1;
            //算出该速度下 吃掉香蕉的时间
            for (auto v : piles)
                retTime += (v + index - 1) / index;

            if (retTime > h) 
            {
                left = index + 1;
            }
            // 保留符合要求的index 并逐步向左寻找更合适的index
            // 比如 6.9 比 6.7 合适 虽然向上取整都算是7
            else 
            {
                right = index;
            }
        }
        return right;
    }
};