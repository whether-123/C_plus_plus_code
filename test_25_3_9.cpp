class Solution {
public:
    int climbStairs(int n) {
        //n=1 时
        int first=1;
        //n=2 时
        int two=2;
        int ret=0;
        
        if(n==1) return 1;
        if(n==2) return 2;

        //将n拆分  
        //第一次跳一个台阶时 只需考虑后面的n-1
        //第一次跳两个台阶时 只需考虑后面的n-2
        //f(n) = f(n-1) + f(n-2)
        for(int i=3;i<=n;i++)
        {
            ret=(first+two);

            first=two;
            two=ret;
        }

        return ret;
    }
};