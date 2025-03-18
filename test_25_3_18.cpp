class Solution {
public:
    int cuttingBamboo(int bamboo_len) 
    {
        vector<int> v(bamboo_len + 1);
        if (bamboo_len == 1 || bamboo_len == 2)
            return 1;
        if (bamboo_len == 3)
            return 2;

        // 作为n>=4的初始条件
        v[1] = 1;
        v[2] = 2;
        v[3] = 3;
        int max = 0;
        //自底向上求解
        for (int i = 4; i <= bamboo_len; ++i)
        {
            //比如 f(3) 不切长度为3 切了后相乘max为 2
            //对于上一次层来说 肯定是需要f(3)=3
            //因为必须要切 对于输入长度 3来说 f(3)=2
            if(i<bamboo_len)
            {
                 max = i;
            }
           
            for (int j = 1; j <= i / 2; ++j)
            {
                if (max < (v[j] * v[i - j]))
                    max = v[j] * v[i - j];
            }
            v[i] = max;
        }

        return v[bamboo_len];
    }
};