class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       vector<int> count(2001,0);
       vector<int> temp(2,0);

        for (size_t i = 0; i < numbers.size(); ++i)
        {
            count[numbers[i] + 1000]++;     //根据范围 映射到数组 0~2000
        }

        int val = 1001; // 超出-1000~1000 保证val没被访问过
        for (size_t j = 0; j < numbers.size();++j)
        {
            //从前往后找 
            if ( (target-numbers[j])>=-1000&&(target-numbers[j])<=1000&&count[target - numbers[j] + 1000] != 0 && val==1001)
            {
                temp[0] = j;
                val = target - numbers[j];
            }
            if (val == numbers[j+1])
            {
                temp[1] = j+1;
                break;       //找到后 终止循环
            }
        }
        return temp;
    }
};