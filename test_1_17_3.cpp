class Solution {
public:
    int firstUniqChar(string s) {
      int Array[26]={0};

      for(auto ch:s)   //利用计数排序的思想，建立一个辅助数组，统计次数
      {
          Array[ch-'a']+=1;
      }
      
      
      for(int i=0;i<s.size();i++)
      {
          if(Array[s[i]-'a']==1)  //字符串 从前往后依次找符合要求的字符 
          return i;
      }
          return -1;     //不存在输出-1
    }
};