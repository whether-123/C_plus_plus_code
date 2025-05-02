class Solution {
public:
    int Min(vector<int>& v, int p2, int p3, int p5) 
    {
        int min = (v[p2] * 2 < v[p3] * 3) ? v[p2] * 2 : v[p3] * 3;

        return (min < v[p5] * 5) ? min : v[p5] * 5;
    }

    int nthUglyNumber(int n) 
    {
        if (n <= 0) 
        {
            return 0;
        }

        // 存储n个丑数
        vector<int> UglyNumArray(n);

        UglyNumArray[0] = 1;

        // 初始化最符合要求的丑数位置
        // UglyNumArray[pUglyNum2]*2 大于 数组中存储的最大丑数
        // 且小于pUglyNum2位置的*2 小于 数组中存储的最大丑数
        // 同理...
        int pUglyNum2 = 0;
        int pUglyNum3 = 0;
        int pUglyNum5 = 0;

        for (int i = 1; i < n; i++) 
        {
            // 取，大于当前存储的最大丑数 && 其中最小的丑数
            int min = Min(UglyNumArray, pUglyNum2, pUglyNum3, pUglyNum5);
            UglyNumArray[i] = min;
            
            // 更新位置
            while (UglyNumArray[pUglyNum2] * 2 <= min) 
            {
                pUglyNum2++;
            }

            while (UglyNumArray[pUglyNum3] * 3 <= min) 
            {
                pUglyNum3++;
            }

            while (UglyNumArray[pUglyNum5] * 5 <= min) 
            {
                pUglyNum5++;
            }
        }
        return UglyNumArray[n - 1];
    }
};