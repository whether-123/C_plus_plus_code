class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> s1;   //利用unordered_set 对元素进行去重
      for(auto number : nums1)
         s1.insert(number);

      unordered_set<int> s2;
      for(auto number : nums2)
         s2.insert(number);

       vector<int> ret;
       for(auto number : s1)     //遍历 相同则入ret
       {
           if(s2.find(number) != s2.end())  //find() 查找失败 返回end()
              ret.push_back(number);
       }

       return ret;
    }
};