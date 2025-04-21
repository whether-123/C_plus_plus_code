class Solution {
public:
    int findNthDigit(int n) 
    {
        if (n < 1)
        {
            return -1;
        }
        // 1~9 都是单个数字，直接返回
        if (n < 10) 
        {
            return n;
        }

        // 1~9  10~99  100~999 ... 拆分成位数相同的区间段
        // 代表区间段中的数字有几位
        int digit = 1;
        while (1)
        {
            // 每个区间段的，一共有多少位
            size_t count = digit * 9 * (size_t)pow(10, digit - 1);

            if (n < count) 
            {
                // 区间段的位权
                int temp = (int)pow(10, digit - 1);
                int prevNumber = temp + n / digit - 1;

                int index = n % digit 
                if (index == 0) 
                {
                    return prevNumber % 10;
                }

                int curNumber = prevNumber + 1;
                int ret;
                for (int i = 0; i < index; i++) 
                {
                    ret = Curnumber / temp;
                    Curnumber %= temp;
                    temp /= 10;
                }

                return ret;
            }
            
            //每次排除掉之前的区间段
            n -= count;
            digit++;
        }
    }
};