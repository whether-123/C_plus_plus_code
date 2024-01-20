class Solution {
public:
    int myAtoi(string str) {
      string number;
    int val = 0;
    int begin = 0;
    int end = str.size();
    char ch = '+';
    int sign=0;
    int sign1=0;
    int max=INT_MAX/10;
    while (begin < end)
    {
        if(str[begin]==' '&&sign==0);
          else 
        if ((str[begin] == '-' || str[begin] == '+')&&sign1==0)
                
                {
                    ch = str[begin];  //符号位
                    sign1=1;
                    sign=1;
                }
       else if (str[begin] >= '0' && str[begin] <= '9')
        {
            number += str[begin]; //将给定的字符串 按照要求留下数字存入新串
               sign=1;
               sign1=1;
        }
        else
          break;
              ++begin;
    }
    int index = 0;

    for (int i = 0; i < number.size(); i++)
    { 
        if(val>max&&ch=='-') //判断是否越界
          return INT_MIN;
          if(val>max&&ch=='+')
          return INT_MAX;
        if(val==max&&((number[i]-'0')>7)&&ch=='-')
        return INT_MIN;
        if(val == max && ((number[i] - '0') > 7) && ch == '+')
         return INT_MAX;

        val *= 10;
        index = (number[i] - '0'); 
        val += index;
       
    }
    if (ch == '-')
        val = -val;

    return val;
    }
};