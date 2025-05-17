class Solution {
  public:
    vector<vector<int> > FindContinuousSequence(int sum) 
    {
        vector<vector<int>> ret;

        //小于3，没有连续的正整数序列可以组成
        if (sum < 3) 
        {
            return ret;
        }

        int first = 1;
        int second = 2;
        //因为要求是连续的，最少两个数组成
        //比如 奇数 15 -> 7，8 (连续的正数，first最大等于7)
        int middle = (sum + 1) / 2;
        int tempsum = first + second;

        while (first < middle) 
        {
            if (tempsum == sum) 
            {
                Count(ret, first, second);
            }

            //因为上一次一定是小于sum的，然后加上了second
            //才大于sum，所以要减掉first，且first++
            while (tempsum > sum && first < middle) 
            {

                tempsum -= first;
                first++;
                if (tempsum == sum) 
                {
                    Count(ret, first, second);
                }
            }

            second++;
            tempsum += second;
        }
        return ret;

    }

    void Count(vector<vector<int>>& v, int first, int second) 
    {
        int position = v.size();
        vector<int> temp;
        while (first <= second) 
        {
            temp.push_back(first++);
        }
        v.push_back(std::move(temp));
    }
};