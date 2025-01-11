class Solution {
public:
    void minadd(char i,char j,char& c,string& temp)
    {
         if((i-'0')&&(j-'0'))  // 本位和为2时 (相加结果为低位的进位)
            {
               temp.insert(temp.begin(), c);
               c='1'; 
            }
            else if((c-'0')+(i-'0')+(j-'0')==2) //进位+本位和 为2 时(满足第一种情况就会跳过)
            {
                temp.insert(temp.begin(), '0');
                c='1';
            }
            else     
            {
                if(c=='0'&&i=='0'&&j=='0')     //进位+本为和 为0时
                   temp.insert(temp.begin(), '0');
                else
                   temp.insert(temp.begin(), '1');  //  进位+本为和 为1 时

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
           temp.insert(temp.begin(), '1');

         return temp;
    }
};