class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      int val=0;
      for(auto number: nums)
      {
          val^=number;  //val的结果为这两个元素异或的结果，且结果不为0
      }

      int j=0;
      for(;j<32;j++)
      {
          if(val&(1<<j)) //从低位往高位 找出val(二进制)第一个为1的位
          break;
      }

      int num1=0;
      int num2=0;

      for(auto number: nums)
      {
          if(number&(1<<j))  //利用这一位 将所有数分成两组(相同的数在同一组)
           {                 //利用异或相异为1的性质，两个只出现一次的数肯定在不同组
               num1^=number;
           }
           else
           {
               num2^=number;
           }
      }

      vector<int> v;   //将得出的两个数存入vector中返回
      v.push_back(num1);
      v.push_back(num2);
        return v;

    }
};