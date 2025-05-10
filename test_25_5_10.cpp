class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> ret;
        deque<int> dque;

        // 先将第一个滑动窗口入队(队列中存入下标)
        for (int i = 0; i < k; i++) 
        {
            while (!dque.empty() && nums[dque.back()] < nums[i]) 
            {
                dque.pop_back();
            }
            dque.push_back(i);
        }

        //先将第一个滑动窗口中的最大值放入数组
        ret.push_back(nums[dque.front()]);
        //从第二个滑动窗口开始
        for (int i = k; i < nums.size(); i++) 
        {
            //比队尾元素大
            while (!dque.empty() && nums[dque.back()] < nums[i]) 
            {
                dque.pop_back();
            }
            dque.push_back(i);

            //队头元素，超出滑动窗口范围
            if (dque.front() < i - k + 1) 
            {
                dque.pop_front();
            }

            //筛选出最大值后，存入数组
            ret.push_back(nums[dque.front()]);
        }

        return ret;
    }
};