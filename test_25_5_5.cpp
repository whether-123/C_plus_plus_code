class Solution {
public:
    int reversePairs(vector<int>& record) 
    {
        vector<int> temp(record.size());
        int count = 0;
        // 利用归并排序的思路，从后往前比较两个相邻的区间
        // 不能从前往后比，会漏掉次数
        _MergeSort(record, temp, 0, record.size() - 1, count);

        return count;
    }

    void _MergeSort(vector<int>& record, vector<int>& temp, int start, int end,int& count) 
    {
        if (start >= end)  return;
       
        int index = (start + end) / 2;
        _MergeSort(record, temp, start, index, count);
        _MergeSort(record, temp, index + 1, end, count);

        int left1 = start;
        int right1 = index;

        int left2 = index + 1;
        int right2 = end;

        int index_temp = end;

        // 从后往前比较两个相邻的区间
        while (right1 >= left1 && right2 >= left2) 
        {
            // right1所指比right2所指的要大，则存在逆序对
            if (record[right1] > record[right2]) 
            {
                temp[index_temp--] = record[right1];
                count += (right2 - left2 + 1);
                right1--;
            } 
            else 
            {
                temp[index_temp--] = record[right2];
                right2--;
            }
        }

        while (right1 >= left1) 
        {
            temp[index_temp--] = record[right1--];
        }

        while (right2 >= left2) 
        {
            temp[index_temp--] = record[right2--];
        }

        while (start <= end) 
        {
            record[start] = temp[start];
            start++;
        }
    }
};