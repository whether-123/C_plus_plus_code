class Solution {
public:
    
    int rabs(int x)   // 将传入的数转化成负数(负数返回其本身)
    {
        if(x>0)
          return -x;
        else
          return x;
    }
    int divide(int a, int b) {
        //四种特殊情况 单独列出
         if(a==0x80000000&&b==-1)
         return 0x7fffffff;
         if(a==0x80000000&&b==1)
         return a;
         if(b==0x80000000)
         {
            if(a==0x80000000)
            return 1;
            else
            return 0;
         }
         
         int val=0;
         int tempa=rabs(a); //因为32位补码负数比正数多表示一位，都转成负数
         
         while(tempa<=rabs(b)) //利用倍加的思想
         {
            int i=1;  
            int tempb=rabs(b);  
            while(tempa<=tempb) //除数绝对值比被除数绝对值大时 重新开始倍加
            {
                tempa-=tempb;
                val+=i;
                if(tempb<=-1073741824) break; //防止下面的语句溢出 (-2^30)
                i+=i;
                tempb+=tempb; 
            }          
         }

         if((a>0&&b<0)||(a<0&&b>0)) // 一正一负返回负数
         return -val;
         else
         return val;
    }
};