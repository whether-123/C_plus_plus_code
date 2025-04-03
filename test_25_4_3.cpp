class Solution {
public:
    vector<vector<int>> ret;
    vector<int> temp;

    // 回溯
    void Trackback(int n, int start, int k) 
    {
        // 剪枝，后续的子集长度都小于k
        if ((temp.size() + (n - start + 1)) < k)
        {
            return;
        }
            
        // 存入满足条件的子集
        if (temp.size() == k) 
        {
            ret.push_back(temp);
        }

        for (int i = start; i <= n; i++) {
            // 每次循环完成从i开始的子集(从i往后)
            // 比如从1开始
            // 1
            // 1，2
            // 1，2，3
            // 1，3
            temp.push_back(i);
            Trackback(n, i + 1, k);
            // nums[i]组合的子集完成后，清除掉
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) 
    {
        Trackback(n, 1, k);
        return ret;
    }
};