class Solution {
public:
    vector<vector<int>> ret;
    vector<int> temp;
    
    //回溯
    void Trackback(vector<int>& nums, int start) 
    {
        //每次进入函数，先入子集
        ret.push_back(temp);

        for (int i = start; i < nums.size(); i++) 
        {
            //每次循环完成从i开始的子集(从i往后)
            //比如从1开始
            //1
            //1，2
            //1，2，3
            //1，3
            temp.push_back(nums[i]);
            Trackback(nums, i + 1);
            //nums[i]组合的子集完成后，清除掉
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        Trackback(nums, 0);
        return ret;
    }
};