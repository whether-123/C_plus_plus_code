class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       //利用哈希表来记录滑动窗口中的字符
       unordered_set<char>  u_hash;
       int len=s.size();
       int left=0,right=0;
       int max=0;

       //当right走到len时，left没必要继续往后走
       //因为后面的子串一定比，前一个出现的短
       while(right<len)
       {
        //统计以left为始的最长不重复子串
          while(right<len)
          {
            //如果元素不存在 则存入 right右移
            //否则跳出循环 left右移
            if(!u_hash.count(s[right])) u_hash.insert(s[right++]);
            else  break;
          }
          if(max<(right-left))  max=right-left;
           u_hash.erase(s[left]);
           left++;
       }

       return max;
    }
};