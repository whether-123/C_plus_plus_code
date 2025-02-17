class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

       vector<int> v;
       //将字符串的a~z  映射到 0~25
       vector<int> count_s(26); 
       vector<int> count_p(26);
       
       int len_s=s.size();
       int len_p=p.size();
       
       if(len_s<len_p) return v;
       //运用滑动窗口的思想维持一个大小为 len_p 的滑动窗口
       //只用比较此窗口内的 含有的各种字符的个数是否相同
       for(int i=0;i<len_p;i++)
       {
         ++count_s[s[i]-'a'];
         ++count_p[p[i]-'a'];
       }

       if(count_s==count_p)  v.push_back(0);
       //p统计完后 只用维持好s的滑动窗口即可
       for(int i=len_p;i<len_s;i++)
       {
         ++count_s[s[i]-'a'];
         --count_s[s[i-len_p]-'a'];

         if(count_s==count_p)  v.push_back(i-len_p+1);
       }

       return v;
    }
};