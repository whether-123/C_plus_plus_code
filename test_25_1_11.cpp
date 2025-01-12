class Solution {
public:
    void minadd(char i,char j,char& c,string& temp)
    {
        if((c-'0')+(i-'0')+(j-'0')>=2)  //进位+本位和 大于2时
        {
            temp+=(c-'0')+(i-'0')+(j-'0')-2+'0';
            c='1';
        }
        else   //进位+本位和 小于2时
        {
            temp+= (c-'0')+(i-'0')+(j-'0')+'0';
            c='0';
        }
    }

    string addBinary(string a, string b) {
         
         string::reverse_iterator ita=a.rbegin();  //反向迭代器
         string::reverse_iterator itb=b.rbegin();
         char c='0';   //初始进位为0
         string temp;

         while(ita!=a.rend()||itb!=b.rend())
         {
             if (ita == a.rend()) //其中一个走完后，后续相加默认为0
                minadd('0', *(itb++), c, temp);
            else if (itb == b.rend())
                minadd(*(ita++), '0', c, temp);
            else
                minadd(*(ita++), *(itb++), c, temp);  //后置++ 
         }
         
         if(c=='1')  //都走完后 存在进位1 加上
           temp+= '1';

          reverse(temp.begin(),temp.end());
         return temp;
    }
};