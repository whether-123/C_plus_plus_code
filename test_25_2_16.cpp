class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       //将字符串的a~z  映射到 0~25
       vector<int> count_s1(26); 
       vector<int> count_s2(26);
       
       int len_s1=s1.size();
       int len_s2=s2.size();
       
       //s1比s2长时 s1的排列不可能是s2的子串
       if(len_s1>len_s2)  return false; 
       //运用滑动窗口的思想维持一个大小为 len_s1 的滑动窗口
       //只用比较此窗口内的 含有的各种字符的个数是否相同
       for(int i=0;i<len_s1;i++)
       {
         ++count_s1[s1[i]-'a'];
         ++count_s2[s2[i]-'a'];
       }

       if(count_s1==count_s2)  return true;
       //s1统计完后 只用维持好s2的滑动窗口即可
       for(int i=len_s1;i<len_s2;i++)
       {
         ++count_s2[s2[i]-'a'];
         --count_s2[s2[i-len_s1]-'a'];

         if(count_s1==count_s2)  return true;
       }

       return false;
    }
};