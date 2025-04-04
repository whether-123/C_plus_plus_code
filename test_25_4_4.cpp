class Solution {
public:
    vector<vector<int>> ret;
    vector<int> temp;

    void Trace(vector<int>& candidates, int target, int start, int sum) 
    {
        //因为都是正数，后续再加都是＞target
        if(sum>target)
        {
            return;
        }
        
        //因为都是正数，后续再加都是＞target
        if (sum == target) 
        {
            ret.push_back(temp);
            return;
        }
        
        int Sum = sum;
        //每次从start的位置开始完后枚举
        for (int i = start; i < candidates.size(); i++) 
        {
            Sum += candidates[i];
            temp.push_back(candidates[i]);
            //这里传入i，为了保证本次位置在下次可以重复计入
            Trace(candidates, target, i, Sum);

            temp.pop_back();
            Sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        Trace(candidates, target, 0, 0);
        return ret;
    }
};