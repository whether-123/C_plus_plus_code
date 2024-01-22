class Solution {
public:
    int singleNumber(vector<int>& nums) {
     int Array[32]={0};  //从二进制角度去理解(int 有32位) 记录每位出现的次数
     for(auto number:nums)
     {
         for(int i=0;i<32;i++)
         {
             if(number&(1<<i)) //利用与和移位操作 
              Array[i]++;
         }
     }
    
    int val=0;
     for(int j=0;j<32;j++)
     {
         if(Array[j]%3!=0) //每位中如果出现的次数不是3的倍数，则该位对应的值记录在val中
         {
             val+=(1<<j);  
         }
     }

     return val;
     }
   
};