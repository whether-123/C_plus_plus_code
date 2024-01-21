class Solution {
public:
    int singleNumber(vector<int>& nums) {
          int index=0;
          for(auto number: nums)
          {
            index^=number;  // 两个相同的数异或值为0   
                                          // 0异或任何数为任何数
          }
          return index;
    }
};