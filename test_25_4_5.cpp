class Solution {
public:
    vector<vector<int>> ret;
    vector<int> temp;
    void Trace(vector<int>& candidates, int target, int start, int sum) 
    {
        // 因为都是正数，后续再加都是＞target
        if (sum > target) 
        {
            return;
        }

        // 因为都是正数，后续再加都是＞target
        if (sum == target)
        {
            ret.push_back(temp);
            return;
        }

        int Sum = sum;
        // 每次从start的位置开始往后枚举
        for (int i = start; i < candidates.size(); i++) 
        {
            // 每次开始枚举，相邻位置相同，只枚举一次
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            Sum += candidates[i];
            temp.push_back(candidates[i]);

            Trace(candidates, target, i + 1, Sum);
            // 下次开始枚举下一个元素
            temp.pop_back();
            Sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        // 数组中有重复的元素，且集合中不能有相同的组合
        // 先对数组进行排序，跳过相同的元素的枚举
        sort(candidates.begin(), candidates.end());
        Trace(candidates, target, 0, 0);
        return ret;
    }
};