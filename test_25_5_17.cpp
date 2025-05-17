class Solution {
  public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) 
    {
        vector<int>  ret;

        if (array.size() == 0)
            return  ret;

        int start = 0;
        int end = array.size() - 1;

        //用两个指针一个指向第一位，一个指向最后一位
        //因为数组是递增排序的，一定可以找到其中一组
        while (start < end)
        {
            int tempsum = array[start] + array[end];
            //小于sum，说明要增大tempsum
            if (tempsum < sum) 
            {
                start++;
            }
            //大于sum，说明要减小tempsum
            else if (tempsum > sum) 
            {
                end--;
            } 
            else 
            {
                break;
            }
        }

        //不满足说明没找到
        if (start < end) 
        {
            ret.push_back(array[start]);
            ret.push_back(array[end]);
        }

        return ret;
    }
};