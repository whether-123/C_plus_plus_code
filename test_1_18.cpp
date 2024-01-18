class Solution {
public:
    string addStrings(string num1, string num2) {
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
};