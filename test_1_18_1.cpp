class Solution {
public:
 string addStrings(string num1, string num2)  //借用加法函数
 {
       string str;
        //模拟串行进位加法器
        int next = 0;
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
         while(end1>=0||end2>=0)    //从后往前遍历
         {
             int index1=0,index2=0;
             if(end1>=0)
                  index1=num1[end1]-'0';

             if(end2>=0)        //不满足条件index2默认为0，不影响高位相加
                index2=num2[end2]-'0';

             int sum=index1+index2+next; 
            
             if(sum>9)  //本位和超过9 进位加1
             {
                 sum-=10;
                 next=1;
             }
             else
                 next=0;

            str+=(sum+'0');
             --end1;
             --end2;
             
         }

         if(next==1)  //最高位的进位要加上
          {
              str+='1';
          }

         reverse(str.begin(),str.end()); //string容器的逆置函数
           return str;
     
    }

 string multiply(string num1, string num2)  
    {
        string str("0");
        string str1;
        int end=num2.size()-1;
        if(num1.size()<num2.size()) //将num1串设置成，长的那个
        {
             swap(num1,num2);
             end=num2.size()-1;
             
        }
        
        int sign=0;
        int sign2=0;
        for(int i=0;i<=end;i++)
        {
            sign=num2[end-i]-'0'; //取出num2的每一位
      
           for(int j=0;j<sign;j++) //利用num2的本位 变成 本位个num1相加 
           {                        
             str1=addStrings(str1,num1); //每一位范围是0~9 每次调用加法函数不超过9次
           }

            sign2=i;
            while(sign2>0)
            {
                str1+='0';      //加完后需要补(取出的每一位，与end的距离)个0
                sign2--;
            }
           str = addStrings(str, str1); //每一位操作完后 加和
           str1="0"; 
        }
        return str;
    }
};