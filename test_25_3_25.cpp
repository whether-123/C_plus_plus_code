class Solution {
public:
    Solution(vector<int>& w)
    {
        preSum.resize(w.size());
        // 计算前缀和
        preSum[0] = w[0];
        for (int i = 1; i < w.size(); i++) 
        {
            preSum[i] = (preSum[i - 1] + w[i]);
        }
        // 设置时间为随机数种子
        srand((size_t)time(NULL));
    }

    int pickIndex() {
        // 保证随机数生成的范围在[1,total]
        int ranNum = rand() % preSum.back() + 1;
        // 比如数组w=[1,2,3,5,9]  preSum=[1,3,6,11,20]
        // 随机生成[1,20]的数  
        //(1),(2 3),(4 5 6),(7~11),(12~20) 为w中的数各自再preSum中占的比例
        int left = 0;
        int right = preSum.size() - 1;
        int index = 0;

        while (left <= right) 
        {
            index = (left + right) >> 1;
            if (preSum[index] == ranNum) 
            {
                return index;
            } 
            else if (preSum[index] > ranNum) 
            {
                right = index - 1;
            } 
            else 
            {
                left = index + 1;
            }
        }
        return left;
    }

private:
    vector<int> preSum;
};