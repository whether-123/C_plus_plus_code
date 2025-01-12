class Solution {
public:
    vector<int> countBits(int n) {
          vector<int> temp(n+1,0);// vector 里面的值初始化后 才能用 operator[]
           int i=0;
        
          for(;i<=n;i++) //依次对每个数处理
          {
            int val=i;
            int count=0;
           while(val!=0) 
           {
             if(val%2==1)  // 对2取余 看最低位是否为1(二进制表示下) 
                ++count;
              val/=2;  //统计完最低位后 右移一位
           }
             temp[i]=count;
          }

          return temp;

    }
};