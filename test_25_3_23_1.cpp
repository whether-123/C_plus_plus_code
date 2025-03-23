class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int left = 0;
        int right = arr.size() - 1;
        int index = 0;

        while (left < right) 
        {
            index = (left + right) >> 1;
            // 此时山顶一定在index的右边(不包括index)
            if (arr[index] < arr[index + 1]) 
            {
                left = index + 1;
            }
            // 此时山顶一定在index的左边(包括index)
            else 
            {
                right = index;
            }
        }
        return left;
    }
};