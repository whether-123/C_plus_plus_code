class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       vector<int>::iterator slow=nums.begin(); //定义两个迭代器
       vector<int>::iterator fast=nums.begin();

       int count=0;   //用于记录满指针走过的长度
       while(fast!=nums.end())
       {         
           if(*fast!=*slow)  //当slow与fase 不同时
           {
               ++slow;
               ++count;     
               *slow=*fast;  //让下一个第一次出现的元素挪到上一个第一次出现的元素后面
           }    
           ++fast; 
       }
       return count+1;
    } 
};